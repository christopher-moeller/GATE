#pragma once

#include "Camera.h"
#include <memory>

namespace Gate {

    class CameraController {
    public:
        CameraController(Camera* camera);
        
        virtual void Init() = 0;
        
        virtual ~CameraController() = default;
        
    protected:
        Camera* m_Camera;
    };

}
