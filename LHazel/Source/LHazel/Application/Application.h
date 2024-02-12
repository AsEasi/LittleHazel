#pragma once

#include "LHazel/Core.h"
#include "LHazel/Window/Window.h"
#include "LHazel/Event/ApplicationEvent.h"
#include "LHazel/Layer/LayerStack.h"
#include "LHazel/ImGui/ImGuiLayer.h"

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
        void PushOverlay(Layer* _Layer);

        inline static Application& Get() { return *_Current; }

        inline Window& GetWindow() { return *_Window; }

    private:

        static Application* _Current;

        bool _Running = false;
        std::unique_ptr<Window> _Window;

        LayerStack _LayerStack;

        bool OnWindowClose(WindowCloseEvent& _Event);
    };

    // To be defined in CLIENT.
    Application* CreateApplication();

}