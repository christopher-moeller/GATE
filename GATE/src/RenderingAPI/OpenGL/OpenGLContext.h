#pragma once
 
#ifdef GATE_PLATFORM_MACOS
#include <glad/glad.h>
#elif defined GATE_PLATFORM_ANDROID
#include <GLES3/gl3.h>
#else
#error "Plattform not supported for OpenGL"
#endif

namespace Gate {

    class OpenGLContext {
    public:
        static void Init();
        
    };
}

