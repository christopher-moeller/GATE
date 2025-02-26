#include "AndroidApplication.h"
#include "Utils/AndroidLogger.h"
#include "Gate/Base.h"


namespace Gate {

    void AndroidApplication::InitInternal() {
        
    }

    void AndroidApplication::Step() {
        
    }

    std::unique_ptr<Logger> AndroidApplication::CreateLogger() {
        return std::make_unique<AndroidLogger>();
    }


}
