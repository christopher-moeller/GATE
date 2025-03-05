#include "AndroidApplication.h"
#include "Utils/AndroidLogger.h"
#include "Gate/Base.h"
#include "Gate/Camera/StandardCamera.h"
#include <chrono>


namespace Gate {

    void AndroidApplication::InitInternal() {
        
    }

    void AndroidApplication::Step() {
        
    }

    std::unique_ptr<Logger> AndroidApplication::CreateLogger() {
        return std::make_unique<AndroidLogger>();
    }


}
