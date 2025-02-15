#pragma once
#include "Event.h"
#include <map>
#include <vector>

namespace Gate {

    class EventManager {
    
        
    public:
        void PushEvent(Event& event);
        void AddListener(EventType type, const std::function<bool(Gate::Event&)>& fun);
        
    private:
        std::map<EventType, std::vector<std::function<bool(Event&)>>> m_Listeners;
        
    };

}
