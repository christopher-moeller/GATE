#include "SPDLogger.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Gate {

    SPDLogger::SPDLogger() {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        m_SpdLogger = spdlog::stderr_color_mt("GATE");
    }

    void SPDLogger::Info(const char *message, ...) {
        va_list args;
        m_SpdLogger->info(message, args);
    }

    void SPDLogger::Error(const char *message, ...) {
        va_list args;
        m_SpdLogger->error(message, args);
    }

}
