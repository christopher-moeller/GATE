#include "ComputerCameraController.h"
#include "Gate/Base.h"
#include "Gate/Utils/KeyCodes.h"
#include "Gate/Camera/StandardCamera.h"
#include <glm/glm.hpp>


namespace Gate {


    void ComputerCameraController::Init() {
        
        StandardCamera* standardCamera = dynamic_cast<StandardCamera*>(m_Camera);
        
        Application* application = Application::Get();
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
    }

}
