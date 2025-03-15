#include "Quad2D.h"
#include "Gate/Application.h"
#include "Gate/Rendering/Shaders/Quad2DShaderSource.h"


namespace Gate {

    Quad2D::Quad2D() {
        Application* app = Application::Get();
            
        m_Shader.reset(app->GetRenderer()->CreateShader(Quad2DShaderSource()));
        m_Shader->Compile();
        
        m_VertexArray.reset(app->GetRenderer()->CreateVertexArray());
        
        float vertices[4 * 3] = {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.5f,  0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f
        };
        
        std::shared_ptr<Gate::VertexBuffer> vertexBuffer;
        vertexBuffer.reset(app->GetRenderer()->CreateVertexBuffer(vertices, sizeof(vertices)));
        Gate::BufferLayout layout = {
                    { Gate::ShaderDataType::Float3, "a_Position" }
                };
        vertexBuffer->SetLayout(layout);
        m_VertexArray->AddVertexBuffer(vertexBuffer);
        
        uint32_t indices[6] = { 0, 1, 2, 0, 2, 3 };
        std::shared_ptr<Gate::IndexBuffer> indexBuffer;
        indexBuffer.reset(app->GetRenderer()->CreateIndexBuffer(indices, sizeof(indices) / sizeof(uint32_t)));
        m_VertexArray->SetIndexBuffer(indexBuffer);
        
        m_VertexArray->Unbind();
    }

    std::shared_ptr<Shader>& Quad2D::GetShader() {
        return m_Shader;
    }

    std::shared_ptr<VertexArray>& Quad2D::GetVertexArray() {
        return m_VertexArray;
    }

}
