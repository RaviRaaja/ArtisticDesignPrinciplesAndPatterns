#include <Employee.h>

using namespace std;

IEmployee *Employee::manager() const { return m_manager; }

void Employee::assignManager(IEmployee *manager) {
  m_manager = std::move(manager);
}
