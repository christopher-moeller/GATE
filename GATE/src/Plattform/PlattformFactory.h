#include "PlattformDefines.h"

#include "Gate/Application.h"

#ifdef GATE_PLATTFORM_MACOS

#include "Plattform/MacOS/MacOSApplication.h"

#elif defined GATE_PLATTFORM_ANDROID

#include "Plattform/Android/AndroidApplication.h"

#else

    #error "No Plattform defined"

#endif

namespace Gate {

    enum Plattform {
        None = 0, Android, MacOs
    };

    Application* CreateNewApplicationInstance() {
        #ifdef GATE_PLATTFORM_MACOS
        return new MacOSApplication();
        #elif defined GATE_PLATTFORM_ANDROID
        return new AndroidApplication();
        #else
            #error "No Plattform defined"
        #endif
    }

    
}


