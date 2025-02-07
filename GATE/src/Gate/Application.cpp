#include "Application.h"

#include "Gate/Base.h"
#include "Platform/PlatformFactory.h"

#include <iostream>

namespace Gate {

    Application* Application::s_Instance = nullptr;

    Application* Application::Get() {
        GATE_ASSERT(s_Instance != nullptr, "Instance not created yet");
        return s_Instance;
    }

    void Application::CreateInstance() {
        GATE_ASSERT(s_Instance == nullptr, "Instance already created");
        s_Instance = PlatformFactory::CreateNewApplicationInstance();
    }

    void Application::DestroyInstance() {
        GATE_ASSERT(s_Instance != nullptr, "Instance not created yet");
        delete s_Instance;
    }

    Application::Application()
    {
        //Logger::Init();
        Gate::Logger::Init();
    }

    Application::~Application() {
        //Logger::Destroy();
    }

}
