#include "LHPCH.h"
#include "WindowsWindow.h"

namespace LHazel
{
    Window* Window::Create(const WindowProperties& _Properties)
    {
        return new WindowsWindow(_Properties);
    }

    WindowsWindow::WindowsWindow(const WindowProperties& _Properties)
    {
        Init(_Properties);
    }

    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(_Window);
    }

    void WindowsWindow::SetVSync(bool _Enable)
    {
        glfwSwapInterval(_Enable ? 1 : 0);

        _Data.VSync = _Enable;
    }
    
    bool WindowsWindow::IsVSync() const
    {
        return _Data.VSync;
    }

    static bool _GLFWInitialized = false;
    
    void WindowsWindow::Init(const WindowProperties& _Properties)
    {
        _Data.Title = _Properties.Title;
        _Data.Width = _Properties.Width;
        _Data.Height = _Properties.Height;

        LH_CORE_INFO("Creating WindowsWindow({0}, {1}, {2})", _Data.Title, _Data.Width, _Data.Height);

        if (!_GLFWInitialized)
        {
            int _Success = glfwInit();

            LH_CORE_ASSERT(_Success, "Initialize GLFW failed.");

            _GLFWInitialized = true;
        }

        // Init GLFW window :

        _Window = glfwCreateWindow(
            _Data.Width, _Data.Height, _Data.Title.c_str(), nullptr, nullptr
        );

        glfwMakeContextCurrent(_Window);
        glfwSetWindowUserPointer(_Window, &_Data);

        // Set VSync :

        SetVSync(true);
    }
    
    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(_Window);
    }
}