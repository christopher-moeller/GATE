#include "Gate.h"
#include "Utils/MacOSUtils.h"
#include <unistd.h>


int main() {
    
    MacOSUtils::EnsureSingleProgramInstance();
    
    Gate::Application::Create();
    Gate::Application* app = Gate::Application::Get();
    app->Init();
    
    bool isRunning = true;
    
    app->GetEventManager()->AddListener(Gate::EventType::WindowClose, [&isRunning](Gate::Event& event) {
        isRunning = false;
        return false;
    });
    
    while (isRunning) {
        app->Step();
    }
    
    delete app;
    
}
