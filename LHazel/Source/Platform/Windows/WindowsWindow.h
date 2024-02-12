#pragma once

#include "LHazel/Window/Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace LHazel
{

    class WindowsWindow : public Window
    {
    public:

        WindowsWindow(const WindowProperties& _Properties);
        virtual ~WindowsWindow();

        void OnUpdate() override;

        virtual unsigned int GetWidth() const override { return _Data.Width; }
        virtual unsigned int GetHeight() const override { return _Data.Height; }

        virtual void SetEventCallback(const std::function<void(Event&)> _EventCallback) override
        {
            _Data.EventCallback = _EventCallback;
        }
        virtual void SetVSync(bool _Enable) override;
        virtual bool IsVSync() const override;

    private:

        struct WindowData
        {
        public:

            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            std::function<void(Event&)> EventCallback;
        };

        GLFWwindow* _Window;
        WindowData _Data;

        virtual void Init(const WindowProperties& _Properties);
        virtual void Shutdown();
    };

}