#ifndef IMANAGED_H
#define IMANAGED_H

#include <IEmployee.h>

class IManaged {
public:
  virtual IEmployee *manager() const = 0;
  virtual void assignManager(IEmployee *manager) = 0;
};

#endif