#include "ExampleTriangleRO.h"
#include "Gate/Application.h"

namespace Gate {

    ExampleTriangleRO::ExampleTriangleRO() {
        
        Application* app = Application::Get();
        
        std::string vertexShaderSource = R"(
            #version 330 core
            
            layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec4 a_Color;

            uniform mat4 u_ViewProjection;
            uniform mat4 u_Transform;

            out vec3 v_Position;
            out vec4 v_Color;

            void main()
            {
                v_Position = a_Position;
                v_Color = a_Color;
                gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);   
            }
        )";

        std::string fragmentShaderSource = R"(
            #version 330 core
            
            layout(location = 0) out vec4 color;

            in vec3 v_Position;
            in vec4 v_Color;

            void main()
            {
                color = vec4(v_Position * 0.5 + 0.5, 1.0);
                color = v_Color;
            }
        )";
            
        m_Shader.reset(app->GetRenderer()->CreateShader(vertexShaderSource, fragmentShaderSource));
        m_Shader->Compile();
        
        m_VertexArray.reset(app->GetRenderer()->CreateVertexArray());
        
        float vertices[3 * 7] = {
            -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
             0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
             0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
        };
        
        
        std::shared_ptr<Gate::VertexBuffer> vertexBuffer;
        vertexBuffer.reset(app->GetRenderer()->CreateVertexBuffer(vertices, sizeof(vertices)));
        Gate::BufferLayout layout = {
                    { Gate::ShaderDataType::Float3, "a_Position" },
                    { Gate::ShaderDataType::Float4, "a_Color" }
                };
        vertexBuffer->SetLayout(layout);
        m_VertexArray->AddVertexBuffer(vertexBuffer);
        
        uint32_t indices[3] = { 0, 1, 2 };
        std::shared_ptr<Gate::IndexBuffer> indexBuffer;
        indexBuffer.reset(app->GetRenderer()->CreateIndexBuffer(indices, sizeof(indices) / sizeof(uint32_t)));
        m_VertexArray->SetIndexBuffer(indexBuffer);
        
        m_VertexArray->Unbind();
    };

    std::shared_ptr<Shader>& ExampleTriangleRO::GetShader() {
        return m_Shader;
    };
    std::shared_ptr<VertexArray>& ExampleTriangleRO::GetVertexArray() {
        return m_VertexArray;
    };

}
