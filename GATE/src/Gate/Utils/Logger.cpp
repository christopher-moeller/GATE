#include "Logger.h"
#include <iostream>

namespace Gate {

    Logger* Logger::s_Instance = nullptr;

    Logger::Logger() {
        
    }

    void Logger::Init() {
        // TODO: assert null
        s_Instance = new Logger();
    }

    void Logger::Destroy() {
        // TODO: assert not null
        delete s_Instance;
    }

    Logger* Logger::Get() {
        // TODO: assert not null
        return s_Instance;
    }

    void Logger::info(const char *message, ...) {
        std::cout << message << std::endl;
    }

    void Logger::error(const char *message, ...) {
        std::cout << message << std::endl;
    }

}
