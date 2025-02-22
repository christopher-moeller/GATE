#pragma once

#include <sstream>

namespace Gate {

    enum class EventType
    {
        None = 0,
        WindowClose,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        ScreenTouchedEvent,
        
    };

    class Event {
        
    public:
        virtual EventType GetType() = 0;
        virtual const char* GetName() const = 0;
        virtual std::string ToString() const { return GetName(); }
        
    };

    class WindowCloseEvent : public Event {
        
    public:
        inline EventType GetType() override { return EventType::WindowClose; };
        inline const char * GetName() const override { return "WindowClose"; };
        
    };


    class MouseEvent : public Event {
        
    public:
        inline double GetXPos() const { return m_XPos; };
        inline double GetYPos() const { return m_YPos; };
        
        std::string ToString() const override {
            std::stringstream ss;
            ss << GetName() << " (" << GetXPos() << "|" << GetYPos() << ")";
            return ss.str();
        }
    protected:
        MouseEvent(double x, double y) : m_XPos(x), m_YPos(y) {}
    private:
        double m_XPos;
        double m_YPos;
        
    };

    class MouseButtonPressedEvent : public MouseEvent {
    public:
        MouseButtonPressedEvent(double x, double y, int button) : MouseEvent(x, y), m_Button(button) {}
        inline int GetButton() { return m_Button; };
        
        inline EventType GetType() override { return EventType::MouseButtonPressed; };
        inline const char * GetName() const override { return "MouseButtonPressed"; };
    private:
        int m_Button;
    };

    class ScreenTouchedEvent : public Event {
    public:
        
        ScreenTouchedEvent(double x, double y) : m_XPos(x), m_YPos(y) {}
        
        inline double GetXPos() const { return m_XPos; };
        inline double GetYPos() const { return m_YPos; };
        
        std::string ToString() const override {
            std::stringstream ss;
            ss << GetName() << " (" << GetXPos() << "|" << GetYPos() << ")";
            return ss.str();
        }
        
        inline EventType GetType() override { return EventType::ScreenTouchedEvent; };
        inline const char * GetName() const override { return "ScreenTouchedEvent"; };

    private:
        double m_XPos;
        double m_YPos;
    };


    inline std::ostream& operator<<(std::ostream& os, const Event& e) {
        return os << e.ToString();
    }
}
