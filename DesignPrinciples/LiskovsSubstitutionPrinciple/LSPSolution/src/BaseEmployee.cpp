#include <BaseEmployee.h>

std::string BaseEmployee::lastName() const { return m_lastName; }
void BaseEmployee::setLastName(const std::string &lastname) {
  m_lastName = lastname;
}

std::string BaseEmployee::firstName() const { return m_firstName; }
void BaseEmployee::setFirstName(const std::string &firstName) {
  m_firstName = firstName;
}

float BaseEmployee::salary() const { return m_salary; }
void BaseEmployee::computeSalary(int level) {
  float baseSalaryPerHour = 10.0;
  m_salary = baseSalaryPerHour + (level * 2);
}