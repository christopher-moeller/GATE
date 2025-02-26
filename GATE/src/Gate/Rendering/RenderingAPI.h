#pragma once

#include "Buffer.h"
#include "VertexArray.h"
#include "Shader.h"

namespace Gate {

    class RenderingAPI {
    public:
        virtual void Init() = 0;
        virtual void Draw(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray) = 0;
        
        virtual VertexBuffer* CreateVertexBuffer(float* vertices, unsigned int size) = 0;
        virtual IndexBuffer* CreateIndexBuffer(unsigned int* indices, unsigned int size) = 0;
        virtual VertexArray* CreateVertexArray() = 0;
        virtual Shader* CreateShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) = 0;
    };

}
