#ifndef CEO_H
#define CEO_H

#include <iostream>
#include <Employee.h>

class Ceo: public Employee {
    void computeSalary(int level) override;
    void assignManager(Employee* manager) override;
    void createPerformanceReport(Employee* employee);
};

#endif