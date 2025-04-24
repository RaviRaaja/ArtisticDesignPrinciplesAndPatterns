#ifndef LOGGER
#define LOGGER

#include "ConcreteLogFilters/DefaultLogFilter.h"
#include "ILogFilter.h"
#include "ILogHandler.h"
#include "LogLevel.h"
#include <memory>
#include <mutex>
#include <vector>

class Logger {
private:
  LogLevel currentLogLevel;
  std::unique_ptr<ILogFilter> logFilter;
  std::vector<std::shared_ptr<ILogHandler>> handlers;
  static std::unique_ptr<Logger> instance;
  static std::mutex mutex;

  Logger(LogLevel logLevel, std::unique_ptr<ILogFilter> filter)
      : currentLogLevel(logLevel), logFilter(std::move(filter)) {}

public:
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;

  static Logger *getInstance() {
    std::lock_guard<std::mutex> lock(mutex);
    if (!instance) {
      instance.reset(
          new Logger(LogLevel::INFO, std::make_unique<DefaultLogFilter>()));
    }
    return instance.get();
  }

  void setLogLevel(LogLevel level);
  void addHandler(std::shared_ptr<ILogHandler> handler);
  void log(const std::string &message, LogLevel level);
};

#endif // LOGGER
