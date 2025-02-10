#pragma once

class MacOSOpenGLNativeWindow {
public:
    MacOSOpenGLNativeWindow(int width, int height, const char* title);
    ~MacOSOpenGLNativeWindow();

    void pollEvents();  // Handle macOS events
    void swapBuffers(); // Swap OpenGL buffers
    bool shouldClose(); // Implement later if needed

private:
    void* window;  // NSWindow pointer (opaque in C++)
    void* glContext; // NSOpenGLContext pointer
};
