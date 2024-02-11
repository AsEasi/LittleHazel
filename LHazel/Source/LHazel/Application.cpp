#include "LHPCH.h"
#include "Application.h"

namespace LHazel
{

    Application::Application()
    {
        _Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        _Running = true;

        LH_CORE_INFO("Application Run()");

        while (_Running)
        {
            _Window->OnUpdate();
        }
    }

}