#include "Application.h"
#include <iostream>

#ifdef GATE_PLATFORM_MACOS

#include "Platform/MacOS/MacOSApplication.h"
#define APPLICATION_CLASS MacOSApplication

#elif defined GATE_PLATFORM_ANDROID

#include "Platform/Android/AndroidApplication.h"
#define APPLICATION_CLASS AndroidApplication

#elif defined GATE_PLATFORM_WINDOWS

#error "Windows currently not supported"

#else

#error "No Platform defined"

#endif


namespace Gate {

    Application* Application::s_Instance = nullptr;

    Application* Application::Get() {
        //GATE_ASSERT(s_Instance != nullptr, "Instance not created yet");
        return s_Instance;
    }

    Application* Application::Create() {
        //GATE_ASSERT(s_Instance == nullptr, "Instance already created");
        s_Instance = static_cast<Application*>(new APPLICATION_CLASS());
        std::cout << "Application of type " << s_Instance->GetPlatformName() << " created!" << std::endl;
        return s_Instance;
    }

    void Application::Destroy() {
        //GATE_ASSERT(s_Instance != nullptr, "Instance not created yet");
        delete s_Instance;
    }

    Application::Application()
    {
        
    }

    Application::~Application() {
        
    }

}
