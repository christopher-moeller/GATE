#pragma once

#include "CameraController.h"

namespace Gate {

    class ComputerCameraController : public CameraController {
    public:
        ComputerCameraController(Camera* camera) : CameraController(camera) {}
        
        void Init() override;
    };

}
