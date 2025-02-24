#pragma once

#include "Gate/Rendering/RenderingAPI.h"

namespace Gate {

    class OpenGLRenderingAPI : public RenderingAPI {
      
        void Init() override;
        void DrawExample() override;
        
    };

}
