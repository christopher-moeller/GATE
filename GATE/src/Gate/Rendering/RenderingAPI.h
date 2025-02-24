#pragma once

namespace Gate {

    class RenderingAPI {
    public:
        virtual void Init() = 0;
        virtual void DrawExample() = 0;
    };

}
