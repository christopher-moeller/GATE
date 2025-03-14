#pragma once

#include <glm/glm.hpp>

#include "Buffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Gate/Rendering/Shaders/ShaderSource.h"

namespace Gate {

    class RenderingAPI {
    public:
        virtual void Init() = 0;
        virtual void Draw(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray) = 0;
        
        virtual void SetClearColor(const glm::vec4& color) = 0;
        virtual void Clear() = 0;
        virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
        
        virtual VertexBuffer* CreateVertexBuffer(float* vertices, unsigned int size) = 0;
        virtual IndexBuffer* CreateIndexBuffer(unsigned int* indices, unsigned int size) = 0;
        virtual VertexArray* CreateVertexArray() = 0;
        virtual Shader* CreateShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) = 0;
        virtual Shader* CreateShader(const ShaderSource& shaderSource) = 0;
    };

}
