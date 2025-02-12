#include "PlatformFactory.h"
#include "Gate/Utils/SPDLogger.h"

#ifdef GATE_PLATFORM_MACOS

#include "Platform/MacOS/MacOSApplication.h"

#elif defined GATE_PLATFORM_ANDROID

#include "Platform/Android/AndroidApplication.h"
#include "Platform/Android/AndroidLogger.h"

#else

#error "No Platform defined"

#endif

namespace Gate {

    Application* PlatformFactory::CreateNewApplicationInstance() {
        #ifdef GATE_PLATFORM_MACOS
                return new MacOSApplication();
        #elif defined GATE_PLATFORM_ANDROID
                return new AndroidApplication();
        #else
        #error "No Platform defined"
        #endif
    }

    Logger* PlatformFactory::CreateNewLoggerInstance() {
        #ifdef GATE_PLATFORM_ANDROID
            return new SPDLogger(); //AndroidLogger();
        #else
            return new SPDLogger();
        #endif
    }

}
