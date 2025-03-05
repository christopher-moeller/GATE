#include "EventManager.h"
#include "Gate/Base.h"

namespace Gate {

    void EventManager::PushEvent(Event &event) {
        //GATE_LOG_INFO("{}", event);
        
        if(m_Listeners.find(event.GetType()) == m_Listeners.end()) {
            return;
        }
        
        std::vector<std::function<bool(Event&)>> listeners = m_Listeners[event.GetType()];
        for (int i = 0; i < listeners.size(); i++) {
            std::function<bool(Event&)> currentFun = listeners[i];
            bool result = currentFun(*(&event));
        }
    }

    void EventManager::AddListener(EventType type, const std::function<bool(Gate::Event&)>& fun) {
        if(m_Listeners.find(type) == m_Listeners.end()) {
            std::vector<std::function<bool(Event&)>> emptyVector;
            m_Listeners.insert({type, emptyVector});
        }
        
        m_Listeners.at(type).push_back(fun);
    }

    bool EventManager::IsKeyPressed(int keyCode) {
        if(m_KeyPressedPollCallback) {
            return m_KeyPressedPollCallback(keyCode);
        }
        return false;
    }

    void EventManager::SetKeyPressedPollCallback(const std::function<bool (int &)> &fun) {
        m_KeyPressedPollCallback = fun;
    }

}
