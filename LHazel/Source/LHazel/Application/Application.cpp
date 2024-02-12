#include "LHPCH.h"
#include "Application.h"

namespace LHazel
{
    Application* Application::_Current = nullptr;

    Application::Application()
    {
        LH_ASSERT((_Current == nullptr), "Application instance already exist.");

        _Current = this;

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

        //LH_CORE_TRACE("{0}", _Event);

        for (auto _Iterator = _LayerStack.rbegin(); _Iterator != _LayerStack.rend(); ++_Iterator)
        {
            if (_Event.Handled) break;

            (*_Iterator)->OnEvent(_Event);
        }
    }

    void Application::PushLayer(Layer* _Layer)
    {
        _LayerStack.PushLayer(_Layer);
    }

    void Application::PushOverlay(Layer* _Overlay)
    {
        _LayerStack.PushOverlay(_Overlay);
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
            for (Layer* _Layer : _LayerStack)
            {
                _Layer->OnUpdate();
            }

            _Window->OnUpdate();
        }
    }

}