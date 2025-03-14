#include "Renderer.h"
#include "Shaders/ShaderSource.h"

namespace Gate {

    Renderer::Renderer(RenderingAPI* renderingAPI){
        m_RenderingAPI.reset(renderingAPI);
    }

    void Renderer::Init() {
        m_RenderingAPI->Init();
    }

    void Renderer::OnTargetResize(uint32_t width, uint32_t height) {
        m_RenderingAPI->SetViewport(0, 0, width, height);
    }

    VertexBuffer* Renderer::CreateVertexBuffer(float *vertices, unsigned int size) {
        return m_RenderingAPI->CreateVertexBuffer(vertices, size);
    }

    IndexBuffer* Renderer::CreateIndexBuffer(unsigned int* indices, unsigned int size) {
        return m_RenderingAPI->CreateIndexBuffer(indices, size);
    }
    VertexArray* Renderer::CreateVertexArray() {
        return m_RenderingAPI->CreateVertexArray();
    }
    Shader* Renderer::CreateShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) {
        return m_RenderingAPI->CreateShader(vertexShaderSource, fragmentShaderSource);
    }
    Shader* Renderer::CreateShader(const ShaderSource& shaderSource) {
        return m_RenderingAPI->CreateShader(shaderSource);
    }
    Scene Renderer::NewScene(Camera* camera) {
        return Scene(m_RenderingAPI, camera);
    }

}
