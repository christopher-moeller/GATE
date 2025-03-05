#include "MacOSApplication.h"
#include <iostream>
#include "Gate/Utils/StdLogger.h"
#include "Gate/Base.h"
#include "Rendering/MacOSWindow.h"
#include "Gate/Camera/StandardCamera.h"

namespace Gate {

    void MacOSApplication::InitInternal() {
        m_Logger = std::make_unique<StdLogger>();
        
        m_Window.reset(new MacOSWindow());
        m_Window->Init();
    }

    void MacOSApplication::Step() {
        m_Window->PollEvents();
        m_Window->SwappBuffers();
    }

    std::unique_ptr<Logger> MacOSApplication::CreateLogger() {
        return std::make_unique<StdLogger>();
    }

    float MacOSApplication::GetTime() {
        return m_Window->GetTime();
    }

}
