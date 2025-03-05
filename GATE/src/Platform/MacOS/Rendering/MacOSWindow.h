#pragma once

#include "Gate/Rendering/Window.h"
#include <GLFW/glfw3.h>

namespace Gate {


    class MacOSWindow : public Window {
    public:
        virtual ~MacOSWindow();
        
        virtual void Init() override;
        virtual void PollEvents() override;
        virtual void SwappBuffers() override;
        virtual void Destroy() override;
        
        float GetTime();
        
    private:
        GLFWwindow* m_NativeWindow;
    };

}
