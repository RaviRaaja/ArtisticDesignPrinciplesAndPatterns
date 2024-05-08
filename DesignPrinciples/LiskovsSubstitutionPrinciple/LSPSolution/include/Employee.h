#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <IManaged.h>
#include <BaseEmployee.h>

using namespace std;

class Employee : public BaseEmployee, IManaged
{
public:
    void assignManager(IEmployee *manager) override;
    IEmployee *manager() const override;

protected:
    IEmployee *m_manager;
};
#endif