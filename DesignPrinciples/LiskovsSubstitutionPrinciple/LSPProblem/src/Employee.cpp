#include <Employee.h>

using namespace std;

string Employee::lastName() const { return m_lastName; }
void Employee::setLastName(const string &lastName) { m_lastName = lastName; }

string Employee::firstName() const { return m_firstName; }
void Employee::setFirstName(const string &firstName) { m_firstName = firstName; }

float Employee::salary() const { return m_salary; }

Employee* Employee::manager() const { return m_manager; }
void Employee::assignManager(Employee* manager)  {
    m_manager = std::move(manager);
}


void Employee::computeSalary(int level) {
    float baseSalaryPerHour = 10.0;
    m_salary = baseSalaryPerHour + (level * 2);
}