#include "AndroidApplication.h"
#include "Utils/AndroidLogger.h"
#include "Gate/Base.h"


namespace Gate {

    void AndroidApplication::InitInternal() {
        
    }

    void AndroidApplication::Step() {
        m_Renderer->DrawExample();
    }

    std::unique_ptr<Logger> AndroidApplication::CreateLogger() {
        return std::make_unique<AndroidLogger>();
    }


}
