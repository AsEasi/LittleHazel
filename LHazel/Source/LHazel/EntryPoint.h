#pragma once

#ifdef LH_PLATFORM_WINDOWS

extern LHazel::Application* LHazel::CreateApplication();

int main()
{
    LHazel::Application* _Application = LHazel::CreateApplication();

    _Application->Run();

    delete _Application;

    return 0;
}

#endif