#include "AndroidLogger.h"

#ifdef GATE_PLATFORM_ANDROID

#include <android/log.h>

namespace Gate {

    void AndroidLogger::Info(const char *message, ...) {
        __android_log_print(ANDROID_LOG_INFO, "TRACKERS", "%s", message);
    }

    void AndroidLogger::Error(const char *message, ...) {
        __android_log_print(ANDROID_LOG_ERROR, "TRACKERS", "%s", message);
    }

}

#endif
