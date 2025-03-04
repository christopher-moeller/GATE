#pragma once
#include "Event.h"
#include <map>
#include <vector>
#include "Gate/Utils/KeyCodes.h"

namespace Gate {

    class EventManager {
    
        
    public:
        void PushEvent(Event& event);
        void AddListener(EventType type, const std::function<bool(Gate::Event&)>& fun);
        bool IsKeyPressed(int keyCode);
        void SetKeyPressedPollCallback(const std::function<bool(int&)>& fun);
        
    private:
        std::map<EventType, std::vector<std::function<bool(Event&)>>> m_Listeners;
        std::function<bool(int&)> m_KeyPressedPollCallback;
    };

}
