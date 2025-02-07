#include <iostream>
#include "Gate.h"


int main() {
    
    Gate::Application::CreateInstance();
    Gate::Application* app = Gate::Application::Get();
    
    std::cout << "Hello: " << app->GetPlatformName() << std::endl;
    
}
