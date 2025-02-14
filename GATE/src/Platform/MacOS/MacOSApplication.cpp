#include "MacOSApplication.h"
#include <iostream>
#include "Gate/Utils/StdLogger.h"

namespace Gate {

    void MacOSApplication::Init() {
        m_Logger = std::make_unique<StdLogger>();
    }

    void MacOSApplication::Step() {
        GetLogger()->Info("STEP");
    }
}
