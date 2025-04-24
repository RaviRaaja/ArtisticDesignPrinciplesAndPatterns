#ifndef LOG_LEVEL_H
#define LOG_LEVEL_H

enum class LogLevel {
  DEBUG = 1, // least priortiy
  INFO,
  WARN,
  ERROR // max priority
};

#endif