#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"
#include "IManager.h"
#include <iostream>

class Manager : public Employee, IManager {
public:
  void computeSalary(int level) override;
  void createPerformanceReport() override;
};

#endif