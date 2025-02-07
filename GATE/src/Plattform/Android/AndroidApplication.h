#pragma once

#include "Gate/Application.h"

namespace Gate {

    class AndroidApplication : public Application {
        
        void Init() override;
        void Step() override;
        
        inline const char* GetPlattformName() override { return "Android"; };
        
    };
}
