#pragma once

#include "Gate/Application.h"
#include "Rendering/MacOSWindow.h"

namespace Gate {

    class MacOSApplication : public Application {
    
    public:
        void Step() override;
        
        inline const char* GetPlatformName() override { return "MacOS"; };
        
        float GetTime() override;

    private:
        std::unique_ptr<MacOSWindow> m_Window;
        
    protected:
        void InitInternal() override;
        std::unique_ptr<Logger> CreateLogger() override;
    };

}
