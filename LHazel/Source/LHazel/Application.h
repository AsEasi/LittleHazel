#pragma once

#include "Core.h"
#include "LHazel/Window.h"
#include "LHazel/Events/ApplicationEvent.h"

namespace LHazel
{

    class LHAZEL_API Application
    {
    public:

        Application();
        ~Application();

        void Run();

        void OnEvent(Event& _Event);

    private:

        bool _Running = false;
        std::unique_ptr<Window> _Window;

        bool OnWindowClose(WindowCloseEvent& _Event);
    };

    // To be defined in CLIENT.
    Application* CreateApplication();

}