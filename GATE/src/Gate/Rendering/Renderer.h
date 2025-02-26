#pragma once

#include "RenderingAPI.h"
#include "Shader.h"
#include "VertexArray.h"

#include <memory>

namespace Gate {

    class Renderer {
    public:
        Renderer(RenderingAPI* renderingAPI);
        void Init();
        void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);
        // void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));
        
        inline std::shared_ptr<RenderingAPI>& GetRenderingApi() { return m_RenderingAPI; }
    private:
        std::shared_ptr<RenderingAPI> m_RenderingAPI;
    };

}
