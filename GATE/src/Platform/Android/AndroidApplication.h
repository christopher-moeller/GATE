#pragma once

#include "Gate/Application.h"

namespace Gate {

    class AndroidApplication : public Application {
        
    public:
        void Step() override;
        
        inline const char* GetPlatformName() override { return "Android"; };
        
    protected:
        void InitInternal() override;
        std::unique_ptr<Logger> CreateLogger() override;
        
    };
}
