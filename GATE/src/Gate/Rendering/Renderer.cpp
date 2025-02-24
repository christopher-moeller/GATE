#include "Renderer.h"

namespace Gate {

    Renderer::Renderer(RenderingAPI* renderingAPI){
        m_RenderingAPI.reset(renderingAPI);
    }

    void Renderer::Init() {
        m_RenderingAPI->Init();
    }

    void Renderer::DrawExample() {
        m_RenderingAPI->DrawExample();
    }

}
