#include "CameraController.h"
#include "Gate/Base.h"


namespace Gate {

    CameraController::CameraController(Camera* camera) : m_Camera(camera) {
        
    }

    bool CameraControllerAppContext::IsKeyPressed(int keyCode) {
        return m_EventManager->IsKeyPressed(keyCode);
    }

}
