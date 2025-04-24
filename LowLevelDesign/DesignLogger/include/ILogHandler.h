#ifndef ILOGHANDLER
#define ILOGHANDLER

#include "LogLevel.h"
#include "string"

class ILogHandler {
public:
  virtual ~ILogHandler() = default;
  virtual void writeLog(LogLevel messageLevel, const std::string &message) = 0;
};

#endif