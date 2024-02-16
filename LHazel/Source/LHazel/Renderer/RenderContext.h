#pragma once

#include "LHazel/Core.h"

namespace LHazel
{

    class RenderContext
    {
    public:

        virtual void Init() = 0;
        virtual void SwapBuffers() = 0;
    };

}

