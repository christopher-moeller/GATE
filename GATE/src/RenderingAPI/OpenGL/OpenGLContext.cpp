#include "OpenGLContext.h"
#include "Gate/Base.h"

#ifdef GATE_PLATFORM_MACOS
#include <GLFW/glfw3.h>
#endif

namespace Gate {

    void OpenGLContext::Init() {
        #ifdef GATE_PLATFORM_MACOS
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            GATE_ASSERT(false, "Failed to initialize GLAD");
            return;
        }
        #endif
    }

}
