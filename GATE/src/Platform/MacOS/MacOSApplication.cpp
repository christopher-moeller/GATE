#include "MacOSApplication.h"
#include "Window/MacOSWindow.h"
#include <iostream>

namespace Gate {

    void MacOSApplication::Init() {
        m_Window = new MacOSWindow();
        m_Window->Init();
        // TODO: delete again
    }

    void MacOSApplication::Step() {
        
    }

}
