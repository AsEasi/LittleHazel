#include "LHPCH.h"
#include "ImGuiLayer.h"
#include "LHazel/Application/Application.h"
#include "LHazel/Input/KeyboardCode.h"

#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"

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
        _IO.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
        _IO.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
        //_IO.ConfigViewportsNoAutoMerge = true;
        //_IO.ConfigViewportsNoTaskBarIcon = true;

        // Setup Dear ImGui style.

        ImGui::StyleColorsDark();

        // Setup Platform/Renderer backends

        GLFWwindow* _GLFWWindow = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

        ImGui_ImplGlfw_InitForOpenGL(_GLFWWindow, true);
        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::OnDetach()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::OnImGui()
    {
        bool _ShowDemoWindow = true;

        ImGui::ShowDemoWindow(&_ShowDemoWindow);
    }

    void ImGuiLayer::OnEvent(Event& _Event)
    {
    }

    void ImGuiLayer::BeginImGui()
    {
        // Start the Dear ImGui frame.

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }
    
    void ImGuiLayer::EndImGui()
    {
        ImGuiIO& _IO = ImGui::GetIO();

        // Set display size.

        Window& _AppWindow = Application::Get().GetWindow();

        _IO.DisplaySize = ImVec2((float)_AppWindow.GetWidth(), (float)_AppWindow.GetHeight());

        // Render.

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Update and Render additional Platform Windows
        // (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
        //  For this specific demo app we could also call glfwMakeContextCurrent(window) directly)

        if (_IO.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* _BackupedCurrentContext = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(_BackupedCurrentContext);
        }
    }
}