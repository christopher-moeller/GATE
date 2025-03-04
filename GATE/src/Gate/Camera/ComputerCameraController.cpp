#include "ComputerCameraController.h"
#include "Gate/Base.h"
#include "Gate/Utils/KeyCodes.h"
#include "Gate/Camera/StandardCamera.h"
#include <glm/glm.hpp>


namespace Gate {


    void ComputerCameraController::Init() {
    
        Application* application = Application::Get();
        
        StandardCamera* standardCamera = dynamic_cast<StandardCamera*>(m_Camera);
        
        /*
        application->GetEventManager()->AddListener(EventType::KeyPressedEvent, [standardCamera](Event& event) {

            KeyPressedEvent* keyPressedEvent = static_cast<KeyPressedEvent*>(&event);
            if(keyPressedEvent->GetKeyCode() == GATE_KEY_UP) {
                standardCamera->Move({0.0f, 0.0f, -0.1f});
            }
            if(keyPressedEvent->GetKeyCode() == GATE_KEY_DOWN) {
                standardCamera->Move({0.0f, 0.0f, 0.1f});
            }
            return true;
        });
         */
    }

    void ComputerCameraController::UpdateOnStep(CameraControllerAppContext& context) {
        
        StandardCamera* standardCamera = dynamic_cast<StandardCamera*>(m_Camera);
        if(context.IsKeyPressed(GATE_KEY_UP)) {
            standardCamera->Move({0.0f, 0.0f, -0.1f});
        }
        if(context.IsKeyPressed(GATE_KEY_DOWN)) {
            standardCamera->Move({0.0f, 0.0f, 0.1f});
        }
    }

}
