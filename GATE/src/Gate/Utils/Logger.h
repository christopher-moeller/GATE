#pragma once

namespace Gate {

    class Logger {
    public:
        Logger();
        static void Init();
        static void Destroy();
        static Logger* Get();
        
        virtual void Info(const char* message, ...) = 0;
        virtual void Error(const char* message, ...) = 0;
    private:
        static Logger* s_Instance;
        
    };

}

#define GATE_LOG_INFO(...)    ::Gate::Logger::Get()->Info(__VA_ARGS__)
#define GATE_LOG_ERROR(...)    ::Gate::Logger::Get()->Error(__VA_ARGS__)
