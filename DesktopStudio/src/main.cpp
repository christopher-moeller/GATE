#include "Gate.h"

#ifdef GATE_PLATFORM_MACOS
#include "Utils/MacOSUtils.h"
#endif

#include "Platform/MacOS/MacOSApplication.h"

#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"


int main() {
    
    #ifdef GATE_PLATFORM_MACOS
    MacOSUtils::EnsureSingleProgramInstance();
    #endif
    
    Gate::Application::Create(1200, 800);
    Gate::Application* app = Gate::Application::Get();
    app->Init();
    
    {
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
    
    bool isRunning = true;
    
    app->GetEventManager()->AddListener(Gate::EventType::WindowClose, [&isRunning](Gate::Event& event) {
        isRunning = false;
        return false;
    });
    
    Gate::ExampleTriangleRO triangle;
    
    Gate::StandardCamera* standardCamera = new Gate::StandardCamera(app->GetWidth(), app->GetHeight());

    Gate::StandardCameraController cameraController(standardCamera, Gate::DeviceType::DESKTOP_COMPUTER);
    cameraController.Init();
    
    while (isRunning) {
        
        Gate::Timestep timestep = app->CalculateNextTimestep();
        
        Gate::Scene scene = app->GetRenderer()->NewScene(standardCamera);
        scene.ClearColor({1.0f, 0.0f, 0.0f, 1.0f});
        scene.Submit(triangle);
        scene.Render();
        
        Gate::CameraControllerAppContext context(app->GetEventManager().get(), timestep);
        cameraController.UpdateOnStep(context);
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        
        ImGui::Begin("Test");
        ImGui::Text("Hello World");
        ImGui::End();
        
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        app->Step();
    }
    
    delete app;
    
}
