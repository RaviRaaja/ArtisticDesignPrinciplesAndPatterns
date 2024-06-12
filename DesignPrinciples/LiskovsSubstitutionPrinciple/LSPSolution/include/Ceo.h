#ifndef CEO_H
#define CEO_H

#include <Employee.h>
#include <IManager.h>
#include <iostream>

class Ceo : public BaseEmployee, IManager {
public:
  void computeSalary(int level) override;
  void createPerformanceReport() override;
};

#endif