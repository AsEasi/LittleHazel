#include "LHPCH.h"
#include "WindowsWindow.h"
#include "LHazel/Event/ApplicationEvent.h"
#include "LHazel/Event/KeyEvent.h"
#include "LHazel/Event/MouseEvent.h"

namespace LHazel
{
    static void GLFWErrorCallback(int _Error, const char* _Description)
    {
        LH_CORE_ERROR("GLFW Error ({0}): {1}", _Error, _Description);
    }

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
        glfwSwapBuffers(_NativeWindow);
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

        LH_CORE_TRACE("Creating WindowsWindow({0}, {1}, {2})", _Data.Title, _Data.Width, _Data.Height);

        if (!_GLFWInitialized)
        {
            int _Success = glfwInit();

            LH_CORE_ASSERT(_Success, "Initialize GLFW failed.");

            glfwSetErrorCallback(GLFWErrorCallback);

            _GLFWInitialized = true;
        }

        // Init GLFW window :

        _NativeWindow = glfwCreateWindow(
            _Data.Width, _Data.Height, _Data.Title.c_str(), nullptr, nullptr
        );

        glfwMakeContextCurrent(_NativeWindow);
        glfwSetWindowUserPointer(_NativeWindow, &_Data);

        // Init Glad :

        int _GladVersion = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        LH_CORE_ASSERT((_GladVersion != 0), "Initialize GLFW failed.");

        // Set VSync :

        SetVSync(true);

        // Set GLFW callbacks :
        #pragma region GLFWCallbacks

        glfwSetWindowSizeCallback(_NativeWindow, [](GLFWwindow* _NativeWindow, int _Width, int _Height)
            {
                WindowData& _Data = *(WindowData*)glfwGetWindowUserPointer(_NativeWindow);
    
                _Data.Width = _Width;
                _Data.Height = _Height;
    
                WindowResizedEvent _Event(_Data.Width, _Data.Height);
    
                _Data.EventCallback(_Event);
            });

        glfwSetWindowCloseCallback(_NativeWindow, [](GLFWwindow* _NativeWindow)
            {
                WindowData& _Data = *(WindowData*)glfwGetWindowUserPointer(_NativeWindow);

                WindowClosedEvent _Event;

                _Data.EventCallback(_Event);
            });

        glfwSetKeyCallback(_NativeWindow, [](GLFWwindow* _NativeWindow, int _Key, int _ScanCode, int _Action, int _Mods)
            {
                WindowData& _Data = *(WindowData*)glfwGetWindowUserPointer(_NativeWindow);

                switch (_Action)
                {
                    case GLFW_PRESS:
                    {
                        KeyPressedEvent _Event(_Key, 0);
                        _Data.EventCallback(_Event);
                        break;
                    }
                    case GLFW_RELEASE:
                    {
                        KeyReleasedEvent _Event(_Key);
                        _Data.EventCallback(_Event);
                        break;
                    }
                    case GLFW_REPEAT:
                    {
                        KeyPressedEvent _Event(_Key, 1);
                        _Data.EventCallback(_Event);
                        break;
                    }
                }
            });

        glfwSetCharCallback(_NativeWindow, [](GLFWwindow* _NativeWindow, unsigned int _Keycode)
            {
                WindowData& _Data = *(WindowData*)glfwGetWindowUserPointer(_NativeWindow);

                KeyTypedEvent _Event(_Keycode);

                _Data.EventCallback(_Event);
            });

        glfwSetMouseButtonCallback(_NativeWindow, [](GLFWwindow* _NativeWindow, int _Button, int _Action, int _Mods)
            {
                WindowData& _Data = *(WindowData*)glfwGetWindowUserPointer(_NativeWindow);

                switch (_Action)
                {
                    case GLFW_PRESS:
                    {
                        MouseButtonPressedEvent _Event(_Button);
                        _Data.EventCallback(_Event);
                        break;
                    }
                    case GLFW_RELEASE:
                    {
                        MouseButtonReleasedEvent _Event(_Button);
                        _Data.EventCallback(_Event);
                        break;
                    }
                }
            });

        glfwSetScrollCallback(_NativeWindow, [](GLFWwindow* _NativeWindow, double _OffsetX, double _OffsetY)
            {
                WindowData& _Data = *(WindowData*)glfwGetWindowUserPointer(_NativeWindow);

                MouseScrolledEvent _Event((float)_OffsetX, (float)_OffsetY);

                _Data.EventCallback(_Event);
            });

        glfwSetCursorPosCallback(_NativeWindow, [](GLFWwindow* _NativeWindow, double _PosX, double _PosY)
            {
                WindowData& _Data = *(WindowData*)glfwGetWindowUserPointer(_NativeWindow);

                MouseMovedEvent _Event((float)_PosX, (float)_PosY);

                _Data.EventCallback(_Event);
            });

        #pragma endregion
    }
    
    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(_NativeWindow);
    }
}