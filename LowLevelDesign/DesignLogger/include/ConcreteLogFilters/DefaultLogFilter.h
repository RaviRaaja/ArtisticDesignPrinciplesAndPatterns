#ifndef DEFAULT_LOG_FILTER
#define DEFAULT_LOG_FILTER

#include "ILogFilter.h"
#include "LogLevel.h"

class DefaultLogFilter : public ILogFilter {
public:
  bool shouldLog(LogLevel currentLevel, LogLevel messageLevel) override;
};

#endif