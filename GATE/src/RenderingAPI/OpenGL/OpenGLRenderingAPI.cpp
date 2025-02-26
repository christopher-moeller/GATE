#include "OpenGLRenderingAPI.h"

#include "OpenGLContext.h"
#include "RenderingAPI/OpenGL/OpenGLBuffer.h"
#include "RenderingAPI/OpenGL/OpenGLShader.h"
#include "RenderingAPI/OpenGL/OpenGLVertexArray.h"

namespace Gate {

    void OpenGLRenderingAPI::Init() {
        
        OpenGLContext::Init();
    }

    void OpenGLRenderingAPI::Draw(const std::shared_ptr<Shader> &shader, const std::shared_ptr<VertexArray> &vertexArray) {
        
        // TODO: should not be here
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        
        shader->Use();
        vertexArray->Bind();
        
        glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
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
