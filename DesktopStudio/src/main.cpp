#include "Gate.h"

#ifdef GATE_PLATFORM_MACOS
#include "Utils/MacOSUtils.h"
#endif

#include "GUI/ImGuiContext.h"
#include "GUI/MainImGuiLayer.h"


int main() {
    
    #ifdef GATE_PLATFORM_MACOS
    MacOSUtils::EnsureSingleProgramInstance();
    #endif
    
    Gate::Application::Create(1200, 800);
    Gate::Application* app = Gate::Application::Get();
    app->Init();
    
    ImGuiContext::Init(app);
    
    bool isRunning = true;
    
    app->GetEventManager()->AddListener(Gate::EventType::WindowClose, [&isRunning](Gate::Event& event) {
        isRunning = false;
        return false;
    });
    
    Gate::ExampleTriangleRO triangle;
    
    Gate::StandardCamera* standardCamera = new Gate::StandardCamera(app->GetWidth(), app->GetHeight());

    Gate::StandardCameraController cameraController(standardCamera, Gate::DeviceType::DESKTOP_COMPUTER);
    cameraController.Init();
    
    MainImGuiLayer imGuiLayer;
    
    while (isRunning) {
        
        Gate::Timestep timestep = app->CalculateNextTimestep();
        
        Gate::Scene scene = app->GetRenderer()->NewScene(standardCamera);
        scene.ClearColor({1.0f, 0.0f, 0.0f, 1.0f});
        scene.Submit(triangle);
        scene.Render();
        
        Gate::CameraControllerAppContext context(app->GetEventManager().get(), timestep);
        cameraController.UpdateOnStep(context);
        
        imGuiLayer.Render();

        app->Step();
    }
    
    delete app;
    
}
