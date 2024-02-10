#pragma once

#include "Event.h"

namespace LHazel
{

    class WindowCloseEvent : public Event
    {
    public:

        WindowCloseEvent() = default;

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class WindowResizeEvent : public Event
    {
    public:

        WindowResizeEvent(unsigned int _Width, unsigned int _Height)
            : _Width(_Width), _Height(_Height) {}

        unsigned int GetWidth() const { return _Width; }
        unsigned int GetHeight() const { return _Height; }

        std::string ToString() const override
        {
            std::stringstream _SS;

            _SS << "WindowResizeEvent: " << _Width << ", " << _Height;

            return _SS.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:

        unsigned int _Width, _Height;
    };

    class AppTickEvent : public Event
    {
    public:
        AppTickEvent() = default;

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() = default;

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() = default;

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

}