#pragma once

#include "Gate/Application.h"
#include "Gate/Rendering/Target/Window.h"

namespace Gate {

    class MacOSApplication : public Application {
    
        
        void Init() override;
        void Step() override;
        
        inline const char* GetPlatformName() override { return "MacOS"; };
        
    private:
        Window* m_Window;
        
    };

}
