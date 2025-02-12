#include "Logger.h"
#include <iostream>
#include "Gate/Base.h"
#include "Platform/PlatformFactory.h"

namespace Gate {

    Logger* Logger::s_Instance = nullptr;

    Logger::Logger() {
        
    }

    void Logger::Init() {
        GATE_ASSERT(s_Instance == nullptr, "Logger already created");
        s_Instance = PlatformFactory::CreateNewLoggerInstance();
    }

    void Logger::Destroy() {
        GATE_ASSERT(s_Instance != nullptr, "Logger not created yet");
        delete s_Instance;
    }

    Logger* Logger::Get() {
        GATE_ASSERT(s_Instance != nullptr, "Logger not created yet");
        return s_Instance;
    }

}
