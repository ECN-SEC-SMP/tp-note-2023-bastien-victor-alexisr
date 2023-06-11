#include <iostream>

enum class LogLevel {
    DEBUG,
    ERROR,
    WARNING,
    INFO,
    NONE
};

extern LogLevel minLogLevel; // The minimum log level to log

void log(LogLevel level, const std::string& message);
void setMinLogLevel(LogLevel level);