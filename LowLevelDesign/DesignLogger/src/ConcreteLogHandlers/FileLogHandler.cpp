#include "ConcreteLogHandlers/FileLogHandler.h"

void FileLogHandler::writeLog(LogLevel level, const std::string &message) {
  std::ofstream file(filePath, std::ios::app);
  if (file.is_open()) {
    file << "[" << toString(level) << "] " << message << "\n";
    file.close();
  }
}
