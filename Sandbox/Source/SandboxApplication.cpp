#include <LHazel.h>

class Sandbox : public LHazel::Application
{
public:

    Sandbox()
    {

    }

    ~Sandbox()
    {

    }
};

LHazel::Application* LHazel::CreateApplication()
{
    return new Sandbox();
}
