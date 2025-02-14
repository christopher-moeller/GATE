#include "MacOSApplication.h"
#include <iostream>
#include "Gate/Utils/StdLogger.h"
#include "Gate/Base.h"
#include "Rendering/MacOSWindow.h"

namespace Gate {

    void MacOSApplication::Init() {
        m_Logger = std::make_unique<StdLogger>();
        
        m_Window.reset(new MacOSWindow());
        m_Window->Init();
    }

    void MacOSApplication::Step() {
        m_Window->PollEvents();
        // Render Triangle
        m_Window->SwappBuffers();
    }
}
