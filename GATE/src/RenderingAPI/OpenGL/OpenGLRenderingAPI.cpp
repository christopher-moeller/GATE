#include "OpenGLRenderingAPI.h"


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "Gate/Rendering/VertexArray.h"

#include "RenderingAPI/OpenGL/OpenGLBuffer.h"
#include "RenderingAPI/OpenGL/OpenGLShader.h"
#include "RenderingAPI/OpenGL/OpenGLVertexArray.h"

namespace Gate {

    void OpenGLRenderingAPI::Init() {
        
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return;
        }
        
        std::string vertexShaderSource = "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\0";
        std::string fragmentShaderSource = "#version 330 core\n"
            "out vec4 FragColor;\n"
            "void main()\n"
            "{\n"
            "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
            "}\n\0";
        
        m_Shader.reset(new OpenGLShader(vertexShaderSource, fragmentShaderSource));
        m_Shader->Compile();
        
        
        m_VertexArray.reset(this->CreateVertexArray());
        

        float vertices[] = {
            -0.5f, -0.5f, 0.0f, // left
             0.5f, -0.5f, 0.0f, // right
             0.0f,  0.5f, 0.0f  // top
        };
        
        
        std::shared_ptr<VertexBuffer> vertexBuffer;
        vertexBuffer.reset(this->CreateVertexBuffer(vertices, sizeof(vertices)));
        BufferLayout layout = {
                    { ShaderDataType::Float3, "a_Pos" }
                };
        vertexBuffer->SetLayout(layout);
        m_VertexArray->AddVertexBuffer(vertexBuffer);
        
        uint32_t indices[3] = { 0, 1, 2 };
        std::shared_ptr<IndexBuffer> indexBuffer;
        indexBuffer.reset(this->CreateIndexBuffer(indices, sizeof(indices) / sizeof(uint32_t)));
        m_VertexArray->SetIndexBuffer(indexBuffer);
        
        m_VertexArray->Unbind();
        
    }

    void OpenGLRenderingAPI::DrawExample() {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        
        m_Shader->Use();
        m_VertexArray->Bind();
        
        glDrawElements(GL_TRIANGLES, m_VertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
    }


    VertexBuffer* OpenGLRenderingAPI::CreateVertexBuffer(float* vertices, unsigned int size) {
        return new OpenGLVertexBuffer(vertices, size);
    }

    IndexBuffer* OpenGLRenderingAPI::CreateIndexBuffer(unsigned int* indices, unsigned int size) {
        return new OpenGLIndexBuffer(indices, size);
    }

    VertexArray* OpenGLRenderingAPI::CreateVertexArray() {
        return new OpenGLVertexArray();
    }
 
}
