#include <Ceo.h>

void Ceo::computeSalary(int level) {
    float baseSalaryPerHour = 90.0;
    m_salary = baseSalaryPerHour + (level * 5);
}

void Ceo::createPerformanceReport(Employee* employee) {
    std::cout << "Performance Review is created for " << employee->firstName() << std::endl;
}

void Ceo::assignManager(Employee* manager) {
    throw runtime_error("Manager cannot be assigned to CEO");
}