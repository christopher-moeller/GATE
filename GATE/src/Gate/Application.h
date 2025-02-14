#pragma once

#include "Gate/Utils/Logger.h"
#include <memory>

namespace Gate {

    class Application
    {
    public:
        static Application* Create();
        static void Destroy();
        static Application* Get();
        Application(Application& obj) = delete;
        
        virtual void Init() = 0;
        virtual void Step() = 0;
        virtual const char* GetPlatformName() = 0;
        
        inline std::unique_ptr<Logger>& GetLogger() { return m_Logger; }
        
    private:
        
        static Application* s_Instance;
        
    protected:
        Application();
        virtual ~Application();
        
        std::unique_ptr<Logger> m_Logger;
    };


}
