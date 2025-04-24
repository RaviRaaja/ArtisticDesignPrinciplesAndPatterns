#ifndef ILOGFILTER
#define ILOGFILTER

#include "LogLevel.h"

class ILogFilter {
public:
  virtual ~ILogFilter() = default;
  virtual bool shouldLog(LogLevel currentLevel, LogLevel messageLevel) = 0;
};

#endif