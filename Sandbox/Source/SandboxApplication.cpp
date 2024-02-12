#include <LHazel.h>

class Sandbox : public LHazel::Application
{
public:

    Sandbox()
    {
        // Add ImGui layer.
        PushOverlay(new LHazel::ImGuiLayer());
    }

    ~Sandbox()
    {

    }
};

LHazel::Application* LHazel::CreateApplication()
{
    return new Sandbox();
}
