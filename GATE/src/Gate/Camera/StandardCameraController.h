#pragma once

#include "CameraController.h"
#include "StandardCamera.h"

namespace Gate {

    class StandardCameraController : public CameraController {
    public:
        StandardCameraController(StandardCamera* standardCamera, DeviceType deviceType) : CameraController(standardCamera, deviceType), m_StandardCamera(standardCamera) {}
        
    private:
        StandardCamera* m_StandardCamera;
        float m_CameraTranslationSpeed = 5.0f;
    protected:
        void InitForDesktopComputer() override;
        void UpdateOnStepForDesktopComputer(CameraControllerAppContext &context) override;
        
    };

}
