#pragma once

#include "LHPCH.h"

#include "LHazel/Core.h"
#include "LHazel/Events/Event.h"

namespace LHazel
{

    struct WindowProperties
    {
    public:

        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProperties(
            const std::string _Title = "Little Hazel Engine",
            unsigned int _Width = 1280,
            unsigned int _Height = 720
        )
            : Title(_Title), Width(_Width), Height(_Height) {}
    };

    class Window
    {
    public:

        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const std::function<void(Event&)> _EventCallback) = 0;
        virtual void SetVSync(bool _Enable) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProperties& _Properties = WindowProperties());
    };

}