#pragma once

namespace Gate
{
    class Window {
    public:
        
        virtual ~Window() = default;
        
        virtual void Init() = 0;
        virtual void PollEvents() = 0;
        virtual void SwappBuffers() = 0;
        virtual void Destroy() = 0;
    };
}
