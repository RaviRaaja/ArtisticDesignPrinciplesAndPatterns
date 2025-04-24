#ifndef CONSOLE_LOG_HANDLER
#define CONSOLE_LOG_HANDLER

#include "ILogHandler.h"
#include "LogLevel.h"
#include "LogUtils.h"
#include <iostream>

class ConsoleLogHandler : public ILogHandler {
public:
  void writeLog(LogLevel messageLevel, const std::string &message) override;
};

#endif