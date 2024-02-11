#include "LHPCH.h"
#include "Application.h"

namespace LHazel
{

    Application::Application()
    {
        _Window = std::unique_ptr<Window>(Window::Create());

        _Window->SetEventCallback(LH_BIND_EVENT_FUNCTION(Application::OnEvent));
    }

    Application::~Application()
    {
    }

    void Application::OnEvent(Event& _Event)
    {
        EventDispatcher _Dispatcher(_Event);

        _Dispatcher.Dispatch<WindowCloseEvent>(LH_BIND_EVENT_FUNCTION(Application::OnWindowClose));

        LH_CORE_TRACE("{0}", _Event);
    }

    bool Application::OnWindowClose(WindowCloseEvent& _Event)
    {
        _Running = false;

        return true;
    }

    void Application::Run()
    {
        _Running = true;

        LH_CORE_TRACE("Application Run()");

        while (_Running)
        {
            _Window->OnUpdate();
        }
    }

}