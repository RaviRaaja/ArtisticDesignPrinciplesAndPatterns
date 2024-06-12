#include "BaseEmployee.h"
#include "Ceo.h"
#include "IManager.h"
#include "Manager.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>

using namespace std;

class LSPSolutionTest : public ::testing::Test {
protected:
  void SetUp() override {}
  void TearDown() override {}
};

TEST_F(LSPSolutionTest, VerifySubstitutabilityOfBaseClass) {
  BaseEmployee *employee = new Employee();
  BaseEmployee *manager = new Manager();
  BaseEmployee *ceo = new Ceo();
  EXPECT_THAT(employee, ::testing::NotNull());
  EXPECT_THAT(manager, ::testing::NotNull());
  EXPECT_THAT(ceo, ::testing::NotNull());
}

TEST_F(LSPSolutionTest, VerifyAssignManagerFunctionality) {
  Employee *employee = new Employee();
  Employee *manager = new Manager();
  employee->assignManager(manager);

  EXPECT_THAT(employee->manager(), ::testing::NotNull());
}

// Entry point for the test program
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}