#include "MacOSApplication.h"
#include "Window/MacOSWindow.h"
#include <iostream>

namespace Gate {

    void MacOSApplication::Init() {
        m_Window.reset(new MacOSWindow());
        m_Window->Init();
        
    }

    void MacOSApplication::Step() {
        m_Window->PollEvents();
        // Render Triangle
        m_Window->SwappBuffers();
    }

}
