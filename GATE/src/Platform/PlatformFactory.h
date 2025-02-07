#pragma once

#include "Gate/Application.h"

#ifdef GATE_PLATFORM_MACOS

#include "Platform/MacOS/MacOSApplication.h"

#elif defined GATE_PLATFORM_ANDROID

#include "Platform/Android/AndroidApplication.h"

#else

    #error "No Platform defined"

#endif

namespace Gate {

    Application* CreateNewApplicationInstance() {
        #ifdef GATE_PLATFORM_MACOS
        return new MacOSApplication();
        #elif defined GATE_PLATFORM_ANDROID
        return new AndroidApplication();
        #else
            #error "No Platform defined"
        #endif
    }

    
}


