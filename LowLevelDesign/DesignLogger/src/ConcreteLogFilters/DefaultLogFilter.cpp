#include "ConcreteLogFilters/DefaultLogFilter.h"

// Note: If client has set loglevel to debug then all levels including debug and
// other should be logged.

// If client set log level as warn then all levels include warn and above should
// be logged. which is warn and error logs will only be logged.

bool DefaultLogFilter::shouldLog(LogLevel currentLevel, LogLevel messageLevel) {
  return static_cast<int>(currentLevel) <= static_cast<int>(messageLevel);
}