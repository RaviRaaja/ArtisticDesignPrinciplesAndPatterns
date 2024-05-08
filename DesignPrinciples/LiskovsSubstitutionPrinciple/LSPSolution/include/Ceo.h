#ifndef CEO_H
#define CEO_H

#include <iostream>
#include <Employee.h>
#include <IManager.h>

class Ceo : public BaseEmployee, IManager
{
public:
    void computeSalary(int level) override;
    void createPerformanceReport();
};

#endif