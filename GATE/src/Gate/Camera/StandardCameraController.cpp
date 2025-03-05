#include "StandardCameraController.h"
#include "Gate/Base.h"
#include "Gate/Utils/KeyCodes.h"
#include "Gate/Camera/StandardCamera.h"
#include <glm/glm.hpp>


namespace Gate {


    void StandardCameraController::InitForDesktopComputer() {
        
    }

    void StandardCameraController::UpdateOnStepForDesktopComputer(CameraControllerAppContext& context) {
        
        glm::vec3 position = m_StandardCamera->GetPosition();
        
        // * m_CameraTranslationSpeed * ts
        
        if(context.IsKeyPressed(GATE_KEY_UP)) {
            position += glm::vec3(0.0f, 0.0f, m_CameraTranslationSpeed * context.GetTimestep() * -1.0f);
        }
        if(context.IsKeyPressed(GATE_KEY_DOWN)) {
            position += glm::vec3(0.0f, 0.0f, m_CameraTranslationSpeed * context.GetTimestep());
        }
        
        m_StandardCamera->SetPosition(position);
    }

}
