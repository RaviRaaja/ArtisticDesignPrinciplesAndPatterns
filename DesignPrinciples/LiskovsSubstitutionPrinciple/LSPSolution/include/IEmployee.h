#ifndef IEMPLOYEE_H
#define IEMPLOYEE_H

#include <string>

class IEmployee
{
public:
    virtual std::string lastName() const = 0;
    virtual void setLastName(const std::string &lastname) = 0;

    virtual std::string firstName() const = 0;
    virtual void setFirstName(const std::string &firstName) = 0;

    virtual float salary() const = 0;
    virtual void computeSalary(int level) = 0;
};

#endif