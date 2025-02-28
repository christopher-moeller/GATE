#include "OpenGLRenderingAPI.h"

#include "OpenGLContext.h"
#include "RenderingAPI/OpenGL/OpenGLBuffer.h"
#include "RenderingAPI/OpenGL/OpenGLShader.h"
#include "RenderingAPI/OpenGL/OpenGLVertexArray.h"

namespace Gate {

    void OpenGLRenderingAPI::Init() {
        
        OpenGLContext::Init();
        glEnable(GL_DEPTH_TEST);
    }

    void OpenGLRenderingAPI::Draw(const std::shared_ptr<Shader> &shader, const std::shared_ptr<VertexArray> &vertexArray) {
        shader->Use();
        vertexArray->Bind();
        
        glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
    }

    void OpenGLRenderingAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
        glViewport(x, y, width, height);
    }

    void OpenGLRenderingAPI::SetClearColor(const glm::vec4 &color) {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void OpenGLRenderingAPI::Clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

    Shader* OpenGLRenderingAPI::CreateShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) {
        return new OpenGLShader(vertexShaderSource, fragmentShaderSource);
    }
 
}
