#pragma once

#include <glm/glm.hpp>

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
        
        void ClearColor(const glm::vec4& color);
        void OnTargetResize(uint32_t width, uint32_t height);
        
        VertexBuffer* CreateVertexBuffer(float* vertices, unsigned int size);
        IndexBuffer* CreateIndexBuffer(unsigned int* indices, unsigned int size);
        VertexArray* CreateVertexArray();
        Shader* CreateShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);

    private:
        std::shared_ptr<RenderingAPI> m_RenderingAPI;
    };

}
