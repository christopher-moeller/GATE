#pragma once

#include "Camera.h"
#include <memory>
#include "Gate/Events/EventManager.h"


namespace Gate {

    class CameraControllerAppContext {
    public:
        CameraControllerAppContext(EventManager* eventManager) : m_EventManager(eventManager) {}
        
        bool IsKeyPressed(int keyCode);
    private:
        EventManager* m_EventManager;
    };

    class CameraController {
    public:
        CameraController(Camera* camera);
        
        virtual void Init() = 0;
        virtual void UpdateOnStep(CameraControllerAppContext& context) = 0;
        
        virtual ~CameraController() = default;
        
    protected:
        Camera* m_Camera;
    };

}
