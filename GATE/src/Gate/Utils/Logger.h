#pragma once

namespace Gate {

    class Logger {
    public:
        Logger();
        static void Init();
        static void Destroy();
        static Logger* Get();
        
        virtual void info(const char* message, ...);
        virtual void error(const char* message, ...);
    private:
        static Logger* s_Instance;
        
    };

}

#define GATE_LOG_INFO(...)    ::Gate::Logger::Get()->info(__VA_ARGS__)
#define GATE_LOG_ERROR(...)    ::Gate::Logger::Get()->error(__VA_ARGS__)
