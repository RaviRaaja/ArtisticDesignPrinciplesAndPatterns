#ifndef RATE_LIMITING_LOG_FILTER
#define RATE_LIMITING_LOG_FILTER

#include "ILogFilter.h"
#include "LogLevel.h"
#include <chrono>
#include <unordered_map>

class RateLimitingLogFilter : public ILogFilter {
private:
  int maxLogsPerMinute;
  std::unordered_map<LogLevel, int> logCounts;
  std::chrono::steady_clock::time_point lastResetTime;

public:
  explicit RateLimitingLogFilter(int maxLogs)
      : maxLogsPerMinute(maxLogs),
        lastResetTime(std::chrono::steady_clock::now()) {}

  bool shouldLog(LogLevel currentLevel, LogLevel messageLevel) override;
};

#endif
