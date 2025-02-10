#pragma once

namespace Gate
{
    class Window {
    public:
        virtual void Init() = 0;
        virtual void SwappBuffers() = 0;
    };
}
