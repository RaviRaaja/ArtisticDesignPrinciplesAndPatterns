#include "Logger.h"

void Logger::setLogLevel(LogLevel level) {
  std::lock_guard<std::mutex> lock(mutex);
  currentLogLevel = level;
}

void Logger::addHandler(std::shared_ptr<ILogHandler> handler) {
  std::lock_guard<std::mutex> lock(mutex);
  handlers.push_back(handler);
}

void Logger::log(const std::string &message, LogLevel level) {
  std::lock_guard<std::mutex> lock(mutex);
  if (logFilter->shouldLog(currentLogLevel, level)) {
    for (const auto &handler : handlers) {
      handler->writeLog(level, message);
    }
  }
}

std::unique_ptr<Logger> Logger::instance = nullptr;
std::mutex Logger::mutex;