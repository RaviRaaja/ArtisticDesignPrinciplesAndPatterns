#ifndef FILE_LOG_HANDLER
#define FILE_LOG_HANDLER

#include "ILogHandler.h"
#include "LogLevel.h"
#include "LogUtils.h"
#include <fstream>

class FileLogHandler : public ILogHandler {
private:
  std::string filePath;

public:
  explicit FileLogHandler(const std::string &path) : filePath(path) {}
  void writeLog(LogLevel messageLevel, const std::string &message) override;
};

#endif