#pragma once

#include <memory>
#include "Gate/Utils/Logger.h"
#include "Gate/Events/EventManager.h"
#include "Gate/Rendering/Renderer.h"
#include "Gate/Camera/CameraController.h"
#include "Gate/Utils/Timestep.h"

namespace Gate {

    class Application
    {
    public:
        static Application* Create(int width, int height);
        static void Destroy();
        static Application* Get();
        Application(Application& obj) = delete;
        
        void Init();
        virtual void Step() = 0;
        virtual const char* GetPlatformName() = 0;
        virtual float GetTime();
        
        inline std::unique_ptr<Logger>& GetLogger() { return m_Logger; }
        inline std::unique_ptr<EventManager>& GetEventManager() { return m_EventManager; }
        
        inline void SetRenderer(Renderer* renderer) { m_Renderer.reset(renderer); }
        
        inline std::shared_ptr<Renderer>& GetRenderer() { return m_Renderer; };
        
        Timestep CalculateNextTimestep();
        
        inline int GetWidth() { return m_Width; }
        inline int GetHeight() { return m_Height; }
        
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
        void SetWidthAndHeight(int width, int height);
        
        
        float m_LastFrameTime = 0.0f;
        
        int m_Width, m_Height;
    };


}
