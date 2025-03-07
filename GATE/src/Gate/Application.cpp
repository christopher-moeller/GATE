#include "Application.h"
#include "Gate/Base.h"
#include <chrono>

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

    Application* Application::Create(int width, int height) {
        GATE_ASSERT(s_Instance == nullptr, "Instance already created");
        s_Instance = static_cast<Application*>(new APPLICATION_CLASS());
        s_Instance->SetWidthAndHeight(width, height);
        
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
        
        m_EventManager->AddListener(EventType::ApplicationResizeEvent, [this](Gate::Event& event) {
            ApplicationResizeEvent* resizeEvent = static_cast<ApplicationResizeEvent*>(&event);
            this->m_Width = resizeEvent->GetWidth();
            this->m_Height = resizeEvent->GetHeight();
            
            this->GetRenderer()->OnTargetResize(this->m_Width, this->m_Height);
            return false;
        });
        
        InitInternal();
        m_Renderer->Init();
    }

    Timestep Application::CalculateNextTimestep() {
        float time = GetTime();
        Timestep timestep = time - m_LastFrameTime;
        m_LastFrameTime = time;
        return timestep;
    }

    float Application::GetTime() {
        using namespace std::chrono;
        static auto start = steady_clock::now();
        auto now = steady_clock::now();
        return duration<float>(now - start).count();
    }


    void Application::SetWidthAndHeight(int width, int height) {
        m_Width = width;
        m_Height = height;
    }


}
