#include "MacOSWindow.h"

namespace Gate {

    void MacOSWindow::Init() {
        m_NativeWindow = new MacOSOpenGLNativeWindow(800, 600, "Metal Window"); // TODO: make smart pointer
    }

    void MacOSWindow::SwappBuffers() {
        m_NativeWindow->swapBuffers();
    }

/*
MetalWindow metalWindow(800, 600, "Metal Window");
bool running = true;
while (running) {
    metalWindow.pollEvents();  // Handle macOS events
    //renderTriangle();     // Render OpenGL content
    metalWindow.swapBuffers(); // Swap OpenGL buffers

    //std::this_thread::sleep_for(std::chrono::milliseconds(16)); // ~60 FPS

    // You can set running = false if you want to exit (e.g., based on user input)
}
 */

/*
GATE_LOG_INFO("Init Window");

if (!glfwInit()) {
    GATE_LOG_ERROR("Failed to initialize GLFW");
    return;
}

glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);


glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // TODO: OpenGL specific
 


// Create a GLFW window
GLFWwindow* window = glfwCreateWindow(1200, 800, "GATE Window", nullptr, nullptr);
if (!window) {
    GATE_LOG_ERROR("Failed to create GLFW window");
    glfwTerminate();
    return;
}

glfwMakeContextCurrent(window);
*/

//glfwPollEvents();
/*

// TODO: should not be here
// Main loop
while (!glfwWindowShouldClose(window)) {

    
    //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    //glClear(GL_COLOR_BUFFER_BIT);
    

    //glfwSwapBuffers(window);
    glfwPollEvents();
}
 */


//glfwDestroyWindow(window);
//glfwTerminate();

}
