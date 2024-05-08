#include <Manager.h>

void Manager::computeSalary(int level)
{
    float baseSalaryPerHour = 18.0;
    m_salary = baseSalaryPerHour + (level * 3);
}

void Manager::createPerformanceReport()
{
    std::cout << "Performance Review is created" << std::endl;
}