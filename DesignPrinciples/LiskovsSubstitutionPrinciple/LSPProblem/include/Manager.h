#ifndef MANAGER_H
#define MANAGER_H

#include <Employee.h>

class Manager : public Employee {
    public:
        void computeSalary(int level) override;
        void createPerformanceReport(Employee* employee);
};


#endif