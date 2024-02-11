#pragma once

#include "Core.h"
#include "LHazel/Window.h"
#include "LHazel/Events/ApplicationEvent.h"
#include "LHazel/LayerStack.h"

namespace LHazel
{

    class LHAZEL_API Application
    {
    public:

        Application();
        ~Application();

        void Run();

        void OnEvent(Event& _Event);

        void PushLayer(Layer* _Layer);
        void PushOverlay(Layer* _Overlay);

    private:

        bool _Running = false;
        std::unique_ptr<Window> _Window;

        LayerStack _LayerStack;

        bool OnWindowClose(WindowCloseEvent& _Event);
    };

    // To be defined in CLIENT.
    Application* CreateApplication();

}