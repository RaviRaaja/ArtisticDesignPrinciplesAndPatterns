#ifndef BASEEMPLOYEE_H
#define BASEEMPLOYEE_H

#include <IEmployee.h>
#include <string>

class BaseEmployee : public IEmployee {
public:
  std::string lastName() const override;
  void setLastName(const std::string &lastname) override;

  std::string firstName() const override;
  void setFirstName(const std::string &firstName) override;

  float salary() const override;
  void computeSalary(int level) override;

protected:
  std::string m_firstName, m_lastName;
  float m_salary;
};

#endif