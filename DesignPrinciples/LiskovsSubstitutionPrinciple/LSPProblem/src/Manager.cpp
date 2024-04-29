#include <Manager.h>

void Manager::computeSalary(int level) {
    float baseSalaryPerHour = 18.0;
    m_salary = baseSalaryPerHour + (level * 3);
}

void Manager::createPerformanceReport(Employee* employee) {
    std::cout << "Performance Review is created for " << employee->firstName() << std::endl;
}