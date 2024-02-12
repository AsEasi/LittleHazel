#pragma once

#include "LHazel/Log/Log.h"

#ifdef LH_PLATFORM_WINDOWS

extern LHazel::Application* LHazel::CreateApplication();

int main()
{
    LHazel::Log::Init();

    LHazel::Application* _Application = LHazel::CreateApplication();

    _Application->Run();

    delete _Application;

    return 0;
}

#endif