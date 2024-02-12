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

        // Init.

        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::OnDetach()
    {
        ImGui_ImplOpenGL3_Shutdown();
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

    void ImGuiLayer::OnEvent(Event& event)
    {
    }

}