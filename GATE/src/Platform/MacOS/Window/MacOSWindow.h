#pragma once

#include "Gate/Rendering/Target/Window.h"
#include "MacOSOpenGLNativeWindow.h"

namespace Gate {

    class MacOSWindow : public Window {
    public:
        virtual void Init() override;
        virtual void SwappBuffers() override;
        
    private:
        MacOSOpenGLNativeWindow* m_NativeWindow;
    };

}
