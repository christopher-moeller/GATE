#pragma once

#include "RenderingAPI.h"
#include <memory>

namespace Gate {

    class Renderer {
    public:
        Renderer(RenderingAPI* renderingAPI);
        void Init();
        void DrawExample();
    private:
        std::unique_ptr<RenderingAPI> m_RenderingAPI;
    };

}
