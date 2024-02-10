#pragma once

#include "Event.h"

namespace LHazel
{

    class KeyEvent : public Event
    {
    public:

        inline int GetKeyCode() const { return _KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:

        KeyEvent(const int _Keycode)
            : _KeyCode(_Keycode) {}

        int _KeyCode;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:

        KeyPressedEvent(const int _Keycode, bool _IsRepeat = false)
            : KeyEvent(_Keycode), _IsRepeat(_IsRepeat) {}

        bool IsRepeat() const { return _IsRepeat; }

        std::string ToString() const override
        {
            std::stringstream _SS;
            _SS << "KeyPressedEvent: " << _KeyCode << " (repeat = " << _IsRepeat << ")";
            return _SS.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)

    private:

        bool _IsRepeat;
    };

    class KeyReleasedEvent : public KeyEvent
    {
    public:

        KeyReleasedEvent(const int _Keycode)
            : KeyEvent(_Keycode) {}

        std::string ToString() const override
        {
            std::stringstream _SS;
            _SS << "KeyReleasedEvent: " << _KeyCode;
            return _SS.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };

    class KeyTypedEvent : public KeyEvent
    {
    public:

        KeyTypedEvent(const int _Keycode)
            : KeyEvent(_Keycode) {}

        std::string ToString() const override
        {
            std::stringstream _SS;
            _SS << "KeyTypedEvent: " << _KeyCode;
            return _SS.str();
        }

        EVENT_CLASS_TYPE(KeyTyped)
    };

}