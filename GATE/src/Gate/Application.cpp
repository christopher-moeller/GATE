#include "Application.h"
#include "Gate/Base.h"

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

#include "RenderingAPI/OpenGL/OpenGLRenderingAPI.h"


namespace Gate {

    Application* Application::s_Instance = nullptr;

    Application* Application::Get() {
        GATE_ASSERT(s_Instance != nullptr, "Instance not created yet");
        return s_Instance;
    }

    Application* Application::Create() {
        GATE_ASSERT(s_Instance == nullptr, "Instance already created");
        s_Instance = static_cast<Application*>(new APPLICATION_CLASS());
        
        RenderingAPI* renderingAPI = new OpenGLRenderingAPI();
        Renderer* renderer = new Renderer(renderingAPI);
        
        s_Instance->SetRenderer(renderer);
        
        return s_Instance;
    }

    void Application::Destroy() {
        GATE_ASSERT(s_Instance != nullptr, "Instance not created yet");
        delete s_Instance;
    }

    Application::Application()
    {
        m_EventManager = std::make_unique<EventManager>();
    }

    Application::~Application() {
        
    }

    void Application::Init() {
        m_Logger = CreateLogger();
        GATE_LOG_INFO("Application for platform {} created", s_Instance->GetPlatformName());
        InitInternal();
        m_Renderer->Init();
    }

}
