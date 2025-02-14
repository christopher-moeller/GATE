#include "Gate.h"
#include "Utils/MacOSUtils.h"
#include <unistd.h>


int main() {
    
    MacOSUtils::EnsureSingleProgramInstance();
    
    Gate::Application::Create();
    Gate::Application* app = Gate::Application::Get();
    app->Init();
    
    app->GetLogger()->Info("Hallo {}", 42);
    
    while (true) {
        sleep(1);
        app->Step();
    }
    
}
