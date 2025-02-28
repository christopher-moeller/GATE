#pragma once

#include <memory>
#include "Gate/Utils/Logger.h"
#include "Gate/Events/EventManager.h"
#include "Gate/Rendering/Renderer.h"
#include "Gate/Camera/CameraController.h"

namespace Gate {

    class Application
    {
    public:
        static Application* Create();
        static void Destroy();
        static Application* Get();
        Application(Application& obj) = delete;
        
        void Init();
        virtual void Step() = 0;
        virtual const char* GetPlatformName() = 0;
        
        inline std::unique_ptr<Logger>& GetLogger() { return m_Logger; }
        inline std::unique_ptr<EventManager>& GetEventManager() { return m_EventManager; }
        
        inline void SetRenderer(Renderer* renderer) { m_Renderer.reset(renderer); }
        
        inline std::shared_ptr<Renderer>& GetRenderer() { return m_Renderer; };
        
        virtual ~Application();
        
    private:
        
        static Application* s_Instance;
        
    protected:
        Application();
        
        std::unique_ptr<Logger> m_Logger;
        std::unique_ptr<EventManager> m_EventManager;
        std::shared_ptr<Renderer> m_Renderer;
        
        virtual void InitInternal() = 0;
        virtual std::unique_ptr<Logger> CreateLogger() = 0;
    };


}
