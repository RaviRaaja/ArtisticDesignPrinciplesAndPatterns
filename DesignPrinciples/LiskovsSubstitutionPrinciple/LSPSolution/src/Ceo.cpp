#include <Ceo.h>

void Ceo::computeSalary(int level)
{
    float baseSalaryPerHour = 90.0;
    m_salary = baseSalaryPerHour + (level * 5);
}

void Ceo::createPerformanceReport()
{
    std::cout << "Performance Review is created " << std::endl;
}
