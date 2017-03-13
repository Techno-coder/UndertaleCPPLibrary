
#include <iostream>
#include "../../headers/core/Logger.h"

ug::Logger ug::Logger::logger;

ug::Logger &ug::Logger::instance() {
    return logger;
}

void ug::Logger::error(const std::string &module, const std::string &message) {
    std::cout << "[" << getStringTime() << "][ERROR] " << module << " : " << message << std::endl;
}

void ug::Logger::debug(const std::string &module, const std::string &message) {
#ifdef DEBUG_MODE
    std::cout << "[" << getStringTime() << "][DEBUG] " << module << " : " << message << std::endl;
#endif
}

std::string ug::Logger::getStringTime() {
    int secondsSinceLaunch = (int) difftime(time(0), start);
    int minutesSinceLaunch = secondsSinceLaunch / 60;
    int moduloSeconds = secondsSinceLaunch % 60;
    return std::to_string(minutesSinceLaunch) + ":" + std::to_string(moduloSeconds);
}

ug::Logger::Logger() : start(time(0)){
}

void ug::Logger::warning(const std::string &module, const std::string &message) {
    std::cout << "[" << getStringTime() << "][WARN] " << module << " : " << message << std::endl;
}

void ug::Logger::info(const std::string &module, const std::string &message) {
    std::cout << "[" << getStringTime() << "][INFO] " << module << " : " << message << std::endl;
}
