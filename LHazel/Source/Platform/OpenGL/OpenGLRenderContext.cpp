#include "LHPCH.h"
#include "OpenGLRenderContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace LHazel
{

    OpenGLRenderContext::OpenGLRenderContext(GLFWwindow* _WindowHandle)
        : _WindowHandle(_WindowHandle)
    {
        LH_CORE_ASSERT((_WindowHandle != nullptr), "Window handle is null.");
    }
    
    void OpenGLRenderContext::Init()
    {
        glfwMakeContextCurrent(_WindowHandle);

        // Init Glad.
        int _GladVersion = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        LH_CORE_ASSERT((_GladVersion != 0), "Initialize Glad failed.");

        // Log OpenGL info.

        const char* _InfoVendor     = (const char*)glGetString(GL_VENDOR);
        const char* _InfoRenderer   = (const char*)glGetString(GL_RENDERER);
        const char* _InfoVersion    = (const char*)glGetString(GL_VERSION);

        LH_CORE_INFO("OpenGL info :\nVendor: {0}\nRenderer: {1}\nVersion: {2}", _InfoVendor, _InfoRenderer, _InfoVersion);
    }
    
    void OpenGLRenderContext::SwapBuffers()
    {
        glfwSwapBuffers(_WindowHandle);
    }

}