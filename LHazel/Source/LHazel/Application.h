#pragma once

#include "Core.h"

namespace LHazel
{

    class LHAZEL_API Application
    {
    public:
        void Run();
    };

    // To be defined in CLIENT.
    Application* CreateApplication();

}