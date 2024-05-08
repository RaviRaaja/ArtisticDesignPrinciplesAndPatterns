#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include "IManager.h"
#include "Employee.h"

class Manager : public Employee, IManager
{
public:
    void computeSalary(int level) override;
    void createPerformanceReport();
};

#endif