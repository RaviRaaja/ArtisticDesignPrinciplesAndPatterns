#include "Ceo.h"
#include "Employee.h"
#include "Manager.h"
#include <chrono>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <thread>

using namespace std;

// Example test fixture
class LSPProblemTest : public ::testing::Test {
protected:
  // Per-test set-up
  void SetUp() override {
    m_employee = new Employee();
    m_manager = new Manager();
    m_ceoAsEmployee = new Ceo();
  }

  // Per-test tear-down
  void TearDown() override {
    // Add any necessary clean-up code
    delete m_employee;
    delete m_manager;
    delete m_ceoAsEmployee;
  }

  Employee *m_employee;
  Manager *m_manager;
  Employee *m_ceoAsEmployee;
};

TEST_F(LSPProblemTest, ceoAsEmployeeInstanceNotNull) {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  EXPECT_THAT(m_ceoAsEmployee, ::testing::NotNull())
      << "Failed to create Ceo Object with Emp Type" << endl;
}

TEST_F(LSPProblemTest, createEmpAndAssignManagerSuccess) {
  m_employee->assignManager(m_manager);
  auto manager = m_employee->manager();
  EXPECT_THAT(manager, ::testing::NotNull())
      << "Manager could not be assigned to employee" << endl;
}

TEST_F(LSPProblemTest, runtimeErrorWhenAssigningManagerToCeo) {

  ASSERT_THROW(m_ceoAsEmployee->assignManager(m_manager), std::runtime_error)
      << "Expect Runtime Error" << endl;
}

// Entry point for the test program
int main(int argc, char  **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
