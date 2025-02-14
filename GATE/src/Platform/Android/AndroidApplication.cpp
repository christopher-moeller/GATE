#include "AndroidApplication.h"
#include "Utils/AndroidLogger.h"


namespace Gate {

    void AndroidApplication::Init() {
        m_Logger = std::make_unique<AndroidLogger>();
    }

    void AndroidApplication::Step() {
        GetLogger()->Info("STEP");
    }


}
