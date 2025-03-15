#pragma once

#include "RenderingObject.h"

namespace Gate {

    class Quad2D : public RenderingObject {
        
    public:
        Quad2D();
        std::shared_ptr<Shader>& GetShader() override;
        std::shared_ptr<VertexArray>& GetVertexArray() override;
        
    private:
        std::shared_ptr<Shader> m_Shader;
        std::shared_ptr<VertexArray> m_VertexArray;
    };

}
