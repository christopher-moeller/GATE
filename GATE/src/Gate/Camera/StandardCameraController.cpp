#include "StandardCameraController.h"
#include "Gate/Base.h"
#include "Gate/Utils/KeyCodes.h"
#include "Gate/Camera/StandardCamera.h"
#include <glm/glm.hpp>


namespace Gate {


    void StandardCameraController::InitForDesktopComputer() {
        
    }

    void StandardCameraController::UpdateOnStepForDesktopComputer(CameraControllerAppContext& context) {
        
        glm::vec3 frontDirection = m_StandardCamera->GetFront();
        glm::vec3 rightDirection = m_StandardCamera->GetRight();
        
        glm::vec3 newPosition = m_StandardCamera->GetPosition();
        float currentY = newPosition.y;
        
        float translationVelocity = m_CameraTranslationSpeed * context.GetTimestep();
        
        if(context.IsKeyPressed(GATE_KEY_UP)) {
            newPosition += frontDirection * translationVelocity;
            newPosition.y = currentY;
        }
        if(context.IsKeyPressed(GATE_KEY_DOWN)) {
            newPosition -= frontDirection * translationVelocity;
            newPosition.y = currentY;
        }
        if(context.IsKeyPressed(GATE_KEY_LEFT)) {
            newPosition -= rightDirection * translationVelocity;
            newPosition.y = currentY;
        }
        if(context.IsKeyPressed(GATE_KEY_RIGHT)) {
            newPosition += rightDirection * translationVelocity;
            newPosition.y = currentY;
        }
        
        m_StandardCamera->SetPosition(newPosition);
        
        float rotationVelocity = m_CameraRotationSpeed * context.GetTimestep();
        float pitch = m_StandardCamera->GetPitch();
        float yaw = m_StandardCamera->GetYaw();
        
        if(context.IsKeyPressed(GATE_KEY_W)) {
            pitch += 1.0f * rotationVelocity;
        }
        if(context.IsKeyPressed(GATE_KEY_S)) {
            pitch -= 1.0f * rotationVelocity;
        }
        if(context.IsKeyPressed(GATE_KEY_D)) {
            yaw += 1.0f * rotationVelocity;
        }
        if(context.IsKeyPressed(GATE_KEY_A)) {
            yaw -= 1.0f * rotationVelocity;
        }
        
        m_StandardCamera->SetRotation(yaw, pitch);
        
    }

}
