#include "LHPCH.h"
#include "ImGuiLayer.h"
#include "LHazel/Application/Application.h"
#include "LHazel/Input/KeyboardCodes.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"

#include <GLFW/glfw3.h>

namespace LHazel
{
    ImGuiLayer::ImGuiLayer()
        : Layer("ImGuiLayer")
    {
    }

    void ImGuiLayer::OnAttach()
    {
        // Setup Dear ImGui context.

        IMGUI_CHECKVERSION();

        ImGui::CreateContext();

        ImGuiIO& _IO = ImGui::GetIO();

        _IO.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        _IO.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

        // Setup Dear ImGui style.

        ImGui::StyleColorsDark();

        // Setup key map.
        _IO.KeyMap[ImGuiKey_Tab]         = LH_KEY_TAB;
        _IO.KeyMap[ImGuiKey_LeftArrow]   = LH_KEY_LEFT;
        _IO.KeyMap[ImGuiKey_RightArrow]  = LH_KEY_RIGHT;
        _IO.KeyMap[ImGuiKey_UpArrow]     = LH_KEY_UP;
        _IO.KeyMap[ImGuiKey_DownArrow]   = LH_KEY_DOWN;
        _IO.KeyMap[ImGuiKey_PageUp]      = LH_KEY_PAGE_UP;
        _IO.KeyMap[ImGuiKey_PageDown]    = LH_KEY_PAGE_DOWN;
        _IO.KeyMap[ImGuiKey_Home]        = LH_KEY_HOME;
        _IO.KeyMap[ImGuiKey_End]         = LH_KEY_END;
        _IO.KeyMap[ImGuiKey_Insert]      = LH_KEY_INSERT;
        _IO.KeyMap[ImGuiKey_Delete]      = LH_KEY_DELETE;
        _IO.KeyMap[ImGuiKey_Backspace]   = LH_KEY_BACKSPACE;
        _IO.KeyMap[ImGuiKey_Space]       = LH_KEY_SPACE;
        _IO.KeyMap[ImGuiKey_Enter]       = LH_KEY_ENTER;
        _IO.KeyMap[ImGuiKey_Escape]      = LH_KEY_ESCAPE;
        _IO.KeyMap[ImGuiKey_A]           = LH_KEY_A;
        _IO.KeyMap[ImGuiKey_C]           = LH_KEY_C;
        _IO.KeyMap[ImGuiKey_V]           = LH_KEY_V;
        _IO.KeyMap[ImGuiKey_X]           = LH_KEY_X;
        _IO.KeyMap[ImGuiKey_Y]           = LH_KEY_Y;
        _IO.KeyMap[ImGuiKey_Z]           = LH_KEY_Z;

        // Init.

        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::OnDetach()
    {
        ImGui_ImplOpenGL3_Shutdown();
        //ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::OnUpdate()
    {
        ImGuiIO& _IO = ImGui::GetIO();

        // Set display size.

        Window& _AppWindow = Application::Get().GetWindow();

        _IO.DisplaySize = ImVec2(_AppWindow.GetWidth(), _AppWindow.GetHeight());

        // Start the Dear ImGui frame.

        ImGui_ImplOpenGL3_NewFrame();
        //ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Update ImGui time.

        float _GLFWTime = (float)glfwGetTime();

        _IO.DeltaTime = _Time > 0.0f ? (_GLFWTime - _Time) : (1.0f / 60.0f);
        
        _Time = _GLFWTime;

        // Show ImGui demo window.

        bool _ShowDemoWindow = true;

        if (_ShowDemoWindow)
        {
            ImGui::ShowDemoWindow(&_ShowDemoWindow);
        }

        // Render.

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::OnEvent(Event& _Event)
    {
        EventDispatcher _Dispatcher(_Event);

        _Dispatcher.Dispatch<WindowResizedEvent>        (LH_BIND_EVENT_FUNCTION(ImGuiLayer::OnWindowResizedEvent));
        _Dispatcher.Dispatch<MouseButtonPressedEvent>   (LH_BIND_EVENT_FUNCTION(ImGuiLayer::OnMouseButtonPressedEvent));
        _Dispatcher.Dispatch<MouseButtonReleasedEvent>  (LH_BIND_EVENT_FUNCTION(ImGuiLayer::OnMouseButtonReleasedEvent));
        _Dispatcher.Dispatch<MouseScrolledEvent>        (LH_BIND_EVENT_FUNCTION(ImGuiLayer::OnMouseScrolledEvent));
        _Dispatcher.Dispatch<MouseMovedEvent>           (LH_BIND_EVENT_FUNCTION(ImGuiLayer::OnMouseMovedEvent));
        _Dispatcher.Dispatch<KeyPressedEvent>           (LH_BIND_EVENT_FUNCTION(ImGuiLayer::OnKeyPressedEvent));
        _Dispatcher.Dispatch<KeyReleasedEvent>          (LH_BIND_EVENT_FUNCTION(ImGuiLayer::OnKeyReleasedEvent));
        _Dispatcher.Dispatch<KeyTypedEvent>             (LH_BIND_EVENT_FUNCTION(ImGuiLayer::OnKeyTypedEvent));
    }

    bool ImGuiLayer::OnWindowResizedEvent(WindowResizedEvent& _Event)
    {
        ImGuiIO& _IO = ImGui::GetIO();

        unsigned int _Width = _Event.GetWidth(), _Height = _Event.GetHeight();

        _IO.DisplaySize = ImVec2(_Width, _Height);
        _IO.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);

        glViewport(0, 0, _Width, _Height);

        return false;
    }

    bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& _Event)
    {
        ImGuiIO& _IO = ImGui::GetIO();

        _IO.MouseDown[_Event.GetMouseButton()] = true;

        return false;
    }

    bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& _Event)
    {
        ImGuiIO& _IO = ImGui::GetIO();

        _IO.MouseDown[_Event.GetMouseButton()] = false;
        
        return false;
    }

    bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& _Event)
    {
        ImGuiIO& _IO = ImGui::GetIO();

        _IO.MouseWheelH += _Event.GetXOffset();
        _IO.MouseWheel  += _Event.GetYOffset();

        return false;
    }

    bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& _Event)
    {
        ImGuiIO& _IO = ImGui::GetIO();

        _IO.MousePos = ImVec2(_Event.GetX(), _Event.GetY());

        return false;
    }

    bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& _Event)
    {
        ImGuiIO& _IO = ImGui::GetIO();

        _IO.KeysDown[_Event.GetKeyCode()] = true;

        _IO.KeyCtrl     = _IO.KeysDown[LH_KEY_LEFT_CONTROL] || _IO.KeysDown[LH_KEY_RIGHT_CONTROL];
        _IO.KeyShift    = _IO.KeysDown[LH_KEY_LEFT_SHIFT]   || _IO.KeysDown[LH_KEY_RIGHT_SHIFT];
        _IO.KeyAlt      = _IO.KeysDown[LH_KEY_LEFT_ALT]     || _IO.KeysDown[LH_KEY_RIGHT_ALT];
        _IO.KeySuper    = _IO.KeysDown[LH_KEY_LEFT_SUPER]   || _IO.KeysDown[LH_KEY_RIGHT_SUPER];

        return false;
    }

    bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& _Event)
    {
        ImGuiIO& _IO = ImGui::GetIO();

        _IO.KeysDown[_Event.GetKeyCode()] = false;

        return false;
    }

    bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& _Event)
    {
        ImGuiIO& _IO = ImGui::GetIO();

        int _Keycode = _Event.GetKeyCode();

        if (_Keycode > 0 && _Keycode < 0x10000)
        {
            _IO.AddInputCharacter((unsigned short)_Keycode);
        }

        return false;
    }

}