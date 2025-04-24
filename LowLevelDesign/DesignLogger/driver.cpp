
#include <iostream>
#include "Logger.h"
#include "LogLevel.h"
#include "ConcreteLogHandlers/ConsoleLogHandler.h"
#include "ConcreteLogHandlers/FileLogHandler.h"

using namespace std;

int main() {
    Logger* logger = Logger::getInstance();

    logger->setLogLevel(LogLevel::DEBUG);

    logger->addHandler(std::make_shared<ConsoleLogHandler>());
    logger->addHandler(std::make_shared<FileLogHandler>("application.log"));

    logger->log("This is a DEBUG message", LogLevel::DEBUG);
    logger->log("This is an INFO message", LogLevel::INFO);
    logger->log("This is a WARN message", LogLevel::WARN);
    logger->log("This is an ERROR message", LogLevel::ERROR);
  
    return 0;
}
