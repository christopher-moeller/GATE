#pragma once

#include "Logger.h"


namespace Gate {

    class StdLogger : public Logger {
        
    protected:
        void LogInfoMessage(const std::string &message) override;
        void LogErrorMessage(const std::string &message) override;
        
    };

}
