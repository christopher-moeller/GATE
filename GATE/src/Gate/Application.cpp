#include "Application.h"

#include "Gate/Base.h"
#include "Platform/PlatformFactory.h"

#include <iostream>

namespace Gate {

    Application* Application::s_Instance = nullptr;

    Application* Application::Get() {
        // TODO: assert not null
        return s_Instance;
    }

    void Application::CreateInstance() {
        // TODO: assert null
        s_Instance = CreateNewApplicationInstance();
    }

    void Application::DestroyInstance() {
        // TODO: assert not null
        delete s_Instance;
    }

    Application::Application()
    {
        Logger::Init();
    }

    Application::~Application() {
        Logger::Destroy();
    }

}
