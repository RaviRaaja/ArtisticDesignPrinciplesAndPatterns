#ifndef LOGGER_UNTILS
#define LOGGER_UNTILS

#include "LogLevel.h"
#include "string"

static std::string toString(LogLevel level) {
  switch (level) {
  case LogLevel::DEBUG:
    return "DEBUG";
  case LogLevel::INFO:
    return "INFO";
  case LogLevel::WARN:
    return "WARN";
  case LogLevel::ERROR:
    return "ERROR";
  default:
    return "UNKNOWN";
  }
}

#endif