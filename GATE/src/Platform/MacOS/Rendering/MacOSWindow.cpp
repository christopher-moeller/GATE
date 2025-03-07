#include "MacOSWindow.h"
#include <stdio.h>
#include "Gate/Base.h"
#include "RenderingAPI/OpenGL/OpenGLContext.h"

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
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE); // Specific for MacOS
         
        int width = Application::Get()->GetWidth();
        int height = Application::Get()->GetHeight();

        // Create a GLFW window
        m_NativeWindow = glfwCreateWindow(width, height, "GATE Window", nullptr, nullptr);
        if (!m_NativeWindow) {
            GATE_LOG_ERROR("Failed to create GLFW window");
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_NativeWindow);
        
        glfwSetWindowUserPointer(m_NativeWindow, Application::Get()->GetEventManager().get());
        GLFWwindow* glfwwindow = m_NativeWindow;
        
        Application::Get()->GetEventManager()->SetKeyPressedPollCallback([glfwwindow](int keycode) {
            auto state = glfwGetKey(glfwwindow, static_cast<int32_t>(keycode));
            return state == GLFW_PRESS;
        });
        
        glfwSetMouseButtonCallback(m_NativeWindow, [](GLFWwindow* window, int button, int action, int mods) {
            
            EventManager* eventManager = (EventManager*) glfwGetWindowUserPointer(window);
            
            double xpos, ypos;
            glfwGetCursorPos(window, &xpos, &ypos);
            
            switch (action) {
                case GLFW_PRESS:
                {
                    //eventManager->Test();
                    MouseButtonPressedEvent event(xpos, ypos, button);
                    eventManager->PushEvent(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    
                    break;
                }
            }
            
        });
        
        glfwSetWindowCloseCallback(m_NativeWindow, [](GLFWwindow* window) {
            EventManager* eventManager = (EventManager*) glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            eventManager->PushEvent(event);
        });
        
        glfwSetKeyCallback(m_NativeWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            EventManager* eventManager = (EventManager*) glfwGetWindowUserPointer(window);
            
            
            switch (action) {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, 0);
                    eventManager->PushEvent(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    eventManager->PushEvent(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, 1);
                    eventManager->PushEvent(event);
                    break;
                }
                    
            }
        });
        
        glfwSetWindowSizeCallback(m_NativeWindow, [](GLFWwindow* window, int width, int height) {
            
        });
        
        glfwSetFramebufferSizeCallback(m_NativeWindow, [](GLFWwindow* window, int width, int height) {
            EventManager* eventManager = (EventManager*) glfwGetWindowUserPointer(window);
            
            ApplicationResizeEvent event(width, height);
            eventManager->PushEvent(event);
        });
         
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
        GATE_LOG_INFO("Window destoyed");
    }

    float MacOSWindow::GetTime() {
        return glfwGetTime();
    }

}
