#include "Renderer.h"

namespace Gate {

    Renderer::Renderer(RenderingAPI* renderingAPI){
        m_RenderingAPI.reset(renderingAPI);
    }

    void Renderer::Init() {
        m_RenderingAPI->Init();
    }

    void Renderer::Submit(const std::shared_ptr<Shader> &shader, const std::shared_ptr<VertexArray> &vertexArray) {
        m_RenderingAPI->Draw(shader, vertexArray);
    }

}
