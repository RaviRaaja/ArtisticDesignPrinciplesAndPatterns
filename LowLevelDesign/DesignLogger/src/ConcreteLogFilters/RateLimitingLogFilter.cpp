#include "ConcreteLogFilters/RateLimitingLogFilter.h"

bool RateLimitingLogFilter::shouldLog(LogLevel currentLevel,
                                      LogLevel messageLevel) {
  auto now = std::chrono::steady_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::minutes>(now - lastResetTime)
          .count();

  if (elapsed >= 1) {
    logCounts.clear();
    lastResetTime = now;
  }

  if (logCounts[messageLevel] < maxLogsPerMinute) {
    logCounts[messageLevel]++;
    return true;
  }
  return false;
}