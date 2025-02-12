#include <iostream>
#include "Gate.h"
#include "Utils/MacOSUtils.h"


int main() {
    
    MacOSUtils::EnsureSingleProgramInstance();
    
    Gate::Application::CreateInstance();
    Gate::Application* app = Gate::Application::Get();
    app->Init();
    
    while (true) {
        app->Step();
    }
    
    GATE_LOG_INFO("Date ist ein Test", 12 , 23, 4);
    
}
