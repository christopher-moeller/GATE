#include "MacOSWindow.h"
#include <stdio.h>
#include "Gate/Base.h"

namespace Gate {

    void GLFWErrorCallback(int error, const char* description) {
        fprintf(stderr, "GLFW Error (%d): %s\n", error, description);
    }

    MacOSWindow::~MacOSWindow() {
        Destroy();
    }

    void MacOSWindow::Init() {
        GATE_LOG_INFO("Init Window");

        glfwSetErrorCallback(GLFWErrorCallback);
        
        glfwSetErrorCallback(GLFWErrorCallback);
        if (!glfwInit()) {
            GATE_LOG_ERROR("Failed to initialize GLFW");
            return;
        }


        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Specific for OpenGL
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Specific for MacOS
         

        // Create a GLFW window
        m_NativeWindow = glfwCreateWindow(1200, 800, "GATE Window", nullptr, nullptr);
        if (!m_NativeWindow) {
            GATE_LOG_ERROR("Failed to create GLFW window");
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_NativeWindow);
         
         
    }

    void MacOSWindow::PollEvents() {
        glfwPollEvents();
    }

    void MacOSWindow::SwappBuffers() {
        glfwSwapBuffers(m_NativeWindow);
    }

    void MacOSWindow::Destroy() {
        glfwDestroyWindow(m_NativeWindow);
        glfwTerminate();
    }

}
