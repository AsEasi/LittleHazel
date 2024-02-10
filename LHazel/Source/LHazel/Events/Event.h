#pragma once

#include "LHazel/Core.h"

namespace LHazel
{

    enum class Enum_EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum Enum_EventCategory
    {
        None = 0,
        EventCategoryApplication    = BIT(0),
        EventCategoryInput          = BIT(1),
        EventCategoryKeyboard       = BIT(2),
        EventCategoryMouse          = BIT(3),
        EventCategoryMouseButton    = BIT(4)
    };

#define EVENT_CLASS_TYPE(Type) \
    static Enum_EventType GetStaticType() { return Enum_EventType::Type; }\
    virtual Enum_EventType GetEventType() const override { return GetStaticType(); }\
    virtual const char* GetName() const override { return #Type; }

#define EVENT_CLASS_CATEGORY(Category) \
    virtual int GetCategoryFlags() const override { return Category; }

    class Event
    {
    public:
        
        bool Handled = false;

        virtual Enum_EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        bool IsInCategory(Enum_EventCategory category) const
        {
            return GetCategoryFlags() & category;
        }
    };

    class EventDispatcher
    {
    public:

        EventDispatcher(Event& _Event)
            : _Event(_Event) {}

        template<typename T>
        bool Dispatch(std::function<bool(T&)> _Function)
        {
            if (_Event.GetEventType() == T::GetStaticType())
            {
                _Event.Handled = _Function(*(T*)&_Event);

                return true;
            }

            return false;
        }

    private:

        Event& _Event;
    };

    // Operator :

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }
}