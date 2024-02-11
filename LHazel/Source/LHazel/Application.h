#pragma once

#include "Core.h"
#include "LHazel/Window.h"

namespace LHazel
{

    class LHAZEL_API Application
    {
    public:

        Application();
        ~Application();

        void Run();

    private:

        bool _Running = false;
        std::unique_ptr<Window> _Window;
    };

    // To be defined in CLIENT.
    Application* CreateApplication();

}