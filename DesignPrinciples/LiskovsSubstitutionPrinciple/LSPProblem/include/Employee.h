#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Manager;

class Employee
{
public:
    virtual void assignManager(Manager* manager);
    virtual void computeSalary(int level);
    virtual ~Employee() = default;

protected:
    string m_firstName, m_lastName;
    float m_salary;
    Manager* m_manager;

public:
    string lastName() const;
    void setLastName(const string &lastName);

    string firstName() const;
    void setFirstName(const string &firstName);

    float salary() const;
};
#endif