#pragma once

#include "Event.h"

namespace LHazel
{

    class MouseButtonEvent : public Event
    {
    public:

        int GetMouseButton() const { return _Button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)

    protected:

        int _Button;

        MouseButtonEvent(const int _Button)
            : _Button(_Button) {}
    };

    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:

        MouseButtonPressedEvent(const int _Button)
            : MouseButtonEvent(_Button) {}

        std::string ToString() const override
        {
            std::stringstream _SS;
            _SS << "MouseButtonPressedEvent: " << _Button;
            return _SS.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:

        MouseButtonReleasedEvent(const int _Button)
            : MouseButtonEvent(_Button) {}

        std::string ToString() const override
        {
            std::stringstream _SS;
            _SS << "MouseButtonReleasedEvent: " << _Button;
            return _SS.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
    
    class MouseMovedEvent : public Event
    {
    public:

        MouseMovedEvent(const float _X, const float _Y)
            : _MouseX(_X), _MouseY(_Y) {}

        float GetX() const { return _MouseX; }
        float GetY() const { return _MouseY; }

        std::string ToString() const override
        {
            std::stringstream _SS;
            _SS << "MouseMovedEvent: " << _MouseX << ", " << _MouseY;
            return _SS.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:

        float _MouseX, _MouseY;
    };

    class MouseScrolledEvent : public Event
    {
    public:

        MouseScrolledEvent(const float _OffsetX, const float _OffsetY)
            : _OffsetX(_OffsetX), _OffsetY(_OffsetY) {}

        float GetXOffset() const { return _OffsetX; }
        float GetYOffset() const { return _OffsetY; }

        std::string ToString() const override
        {
            std::stringstream _SS;
            _SS << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
            return _SS.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:

        float _OffsetX, _OffsetY;
    };

}