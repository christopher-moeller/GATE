#include "StandardCameraController.h"
#include "Gate/Base.h"
#include "Gate/Utils/KeyCodes.h"
#include "Gate/Camera/StandardCamera.h"
#include <glm/glm.hpp>


namespace Gate {

    void StandardCameraController::InitForMobileDevice() {
        InitResizeHandling();
    }

    void StandardCameraController::InitForDesktopComputer() {
        InitResizeHandling();
    }

    void StandardCameraController::UpdateOnStepForDesktopComputer(CameraControllerAppContext& context) {
        
        glm::vec3 frontDirection = m_StandardCamera->GetFront();
        glm::vec3 rightDirection = m_StandardCamera->GetRight();
        
        glm::vec3 newPosition = m_StandardCamera->GetPosition();
        
        float translationVelocity = m_CameraTranslationSpeed * context.GetTimestep();
        
        if(context.IsKeyPressed(GATE_KEY_UP)) {
            newPosition += frontDirection * translationVelocity;
        }
        if(context.IsKeyPressed(GATE_KEY_DOWN)) {
            newPosition -= frontDirection * translationVelocity;
        }
        if(context.IsKeyPressed(GATE_KEY_LEFT)) {
            newPosition -= rightDirection * translationVelocity;
        }
        if(context.IsKeyPressed(GATE_KEY_RIGHT)) {
            newPosition += rightDirection * translationVelocity;
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

    void StandardCameraController::InitResizeHandling() {
        Application::Get()->GetEventManager()->AddListener(Gate::EventType::ApplicationResizeEvent, [this](Gate::Event& event) {
            Gate::ApplicationResizeEvent* resizeEvent = static_cast<Gate::ApplicationResizeEvent*>(&event);
            float aspectRatio = static_cast<float>(resizeEvent->GetWidth()) / static_cast<float>(resizeEvent->GetHeight());
            this->m_StandardCamera->SetAspectRatio(aspectRatio);
            return false;
        });
    }

}
