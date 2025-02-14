#pragma once

#include "Gate/Application.h"
#include "Gate/Rendering/Window.h"

namespace Gate {

    class MacOSApplication : public Application {
    
    public:
        
        void Init() override;
        void Step() override;
        
        inline const char* GetPlatformName() override { return "MacOS"; };

    private:
        std::unique_ptr<Window> m_Window;
    };

}
