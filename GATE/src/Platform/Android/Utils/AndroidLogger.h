#pragma once

#include "Gate/Utils/Logger.h"


namespace Gate {

class AndroidLogger : public Logger {
    
    public:
        void LogInfoMessage(const std::string &message) override;
        void LogErrorMessage(const std::string &message) override;
        
    };

}
