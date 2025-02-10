#pragma once

#include "Gate/Application.h"
#include "Gate/Base.h"
#include "Gate/Utils/Logger.h"
#include "Gate/Rendering/Target/Window.h"

namespace Gate {

    class PlatformFactory {

    public:
        static Application* CreateNewApplicationInstance();
        static Logger* CreateNewLoggerInstance();
        static Window* CreateNewWindow();
    };
    
}


