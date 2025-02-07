#pragma once

namespace Gate {

    class Application
    {
    public:
        static void CreateInstance();
        static void DestroyInstance();
        static Application* Get();
        Application(Application& obj) = delete;
        
        virtual void Init() = 0;
        virtual void Step() = 0;
        virtual const char* GetPlatformName() = 0;
        
    private:
        
        static Application* s_Instance;
        
    protected:
        Application();
        ~Application();
    };


}
