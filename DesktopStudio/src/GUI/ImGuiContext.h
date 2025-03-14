#pragma once

#include "Gate.h"

#include "Platform/MacOS/MacOSApplication.h"

#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class ImGuiContext {
  
public:
    
    static void Init(Gate::Application* app) {
        
        Gate::MacOSApplication* macApp = static_cast<Gate::MacOSApplication*>(app);
        GLFWwindow* glfwWindow = macApp->GetMacOSWindow()->GetNativeWindow();
        
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        (void)io;
        
        // Setup ImGui style
        ImGui::StyleColorsDark();
        
        ImGui_ImplGlfw_InitForOpenGL(glfwWindow, true);
        ImGui_ImplOpenGL3_Init("#version 410");
        
    }
    
};
