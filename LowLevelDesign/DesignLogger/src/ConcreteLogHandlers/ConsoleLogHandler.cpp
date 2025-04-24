#include "ConcreteLogHandlers/ConsoleLogHandler.h"

void ConsoleLogHandler::writeLog(LogLevel level, const std::string &message) {
  std::cout << "[" << toString(level) << "] " << message << std::endl;
}
