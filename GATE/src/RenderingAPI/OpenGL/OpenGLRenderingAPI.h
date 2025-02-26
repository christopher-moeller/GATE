#pragma once

#include "Gate/Rendering/RenderingAPI.h"

#include "RenderingAPI/OpenGL/OpenGLShader.h"

namespace Gate {

    class OpenGLRenderingAPI : public RenderingAPI {
      
    public:
        void Init() override;
        void Draw(const std::shared_ptr<Shader> &shader, const std::shared_ptr<VertexArray> &vertexArray) override;
        
        VertexBuffer* CreateVertexBuffer(float* vertices, unsigned int size) override;
        IndexBuffer* CreateIndexBuffer(unsigned int* indices, unsigned int size) override;
        VertexArray* CreateVertexArray() override;
        Shader* CreateShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) override;
        
    private:
        std::shared_ptr<Shader> m_Shader;
        std::shared_ptr<VertexArray> m_VertexArray;
        
    };

}
