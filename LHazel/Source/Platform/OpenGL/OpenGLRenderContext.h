#pragma once

#include "LHazel/Core.h"
#include "LHazel/Renderer/RenderContext.h"

struct GLFWwindow;

namespace LHazel
{

    class OpenGLRenderContext : public RenderContext
    {
    public:

        OpenGLRenderContext(GLFWwindow* _WindowHandle);

        virtual void Init() override;
        virtual void SwapBuffers() override;

    private:

        GLFWwindow* _WindowHandle;
    };

}