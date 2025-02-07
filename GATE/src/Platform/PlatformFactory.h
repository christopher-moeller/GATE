#pragma once

#include "Gate/Application.h"
#include "Gate/Base.h"
#include "Gate/Utils/Logger.h"

namespace Gate {

    class PlatformFactory {

    public:
        static Application* CreateNewApplicationInstance();
        static Logger* CreateNewLoggerInstance();
    };
    
}


