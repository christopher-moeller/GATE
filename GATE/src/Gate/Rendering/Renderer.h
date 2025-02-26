#pragma once

#include "RenderingAPI.h"
#include <memory>

namespace Gate {

    class Renderer {
    public:
        Renderer(RenderingAPI* renderingAPI);
        void Init();
        void DrawExample();
        // void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));
    private:
        std::unique_ptr<RenderingAPI> m_RenderingAPI;
    };

}
