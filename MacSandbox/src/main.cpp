#include <iostream>
#include "Gate.h"


int main() {
    
    Gate::Application::CreateInstance();
    Gate::Application* app = Gate::Application::Get();
    app->Init();
    
    GATE_LOG_INFO("Date ist ein Test", 12 , 23, 4);
    
}
