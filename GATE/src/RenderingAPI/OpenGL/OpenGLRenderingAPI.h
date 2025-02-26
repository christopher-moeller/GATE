#pragma once

#include "Gate/Rendering/RenderingAPI.h"

#include "RenderingAPI/OpenGL/OpenGLShader.h"

namespace Gate {

    class OpenGLRenderingAPI : public RenderingAPI {
      
    public:
        void Init() override;
        void DrawExample() override;
        
        VertexBuffer* CreateVertexBuffer(float* vertices, unsigned int size) override;
        IndexBuffer* CreateIndexBuffer(unsigned int* indices, unsigned int size) override;
        VertexArray* CreateVertexArray() override;
        
    private:
        std::shared_ptr<OpenGLShader> m_Shader;
        std::shared_ptr<VertexArray> m_VertexArray;
        
    };

}
