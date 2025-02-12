#include "Logger.h"
#include "spdlog/spdlog.h"

namespace Gate {

    class SPDLogger : public Logger {
    
    public:
        SPDLogger();
        
        void Info(const char *message, ...) override;
        void Error(const char *message, ...) override;
        
    private:
        std::shared_ptr<spdlog::logger> m_SpdLogger;
    };
}
