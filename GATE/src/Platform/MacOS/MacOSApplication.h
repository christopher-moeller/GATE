#pragma once

#include "Gate/Application.h"

namespace Gate {

    class MacOSApplication : public Application {
    
    public:
        
        void Init() override;
        void Step() override;
        
        inline const char* GetPlatformName() override { return "MacOS"; };

    };

}
