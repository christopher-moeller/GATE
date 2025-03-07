#pragma once

#include <memory>
#include "Gate/Rendering/Shader.h"
#include "Gate/Rendering/VertexArray.h"

namespace Gate {

    class RenderingObject {
        
    public:
        virtual std::shared_ptr<Shader>& GetShader() = 0;
        virtual std::shared_ptr<VertexArray>& GetVertexArray() = 0;
        
    };

}
