#include "Gate.h"
#include "Utils/MacOSUtils.h"
#include <GLFW/glfw3.h>


int main() {
    
    MacOSUtils::EnsureSingleProgramInstance();
    
    Gate::Application::Create(1200, 800);
    Gate::Application* app = Gate::Application::Get();
    app->Init();
    
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

        app->Step();
    }
    
    delete app;
    
}
