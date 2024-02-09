#pragma once

#ifdef LH_PLATFORM_WINDOWS
    #ifdef LH_BUILD_DLL
        #define LHAZEL_API __declspec(dllexport)
    #else
        #define LHAZEL_API __declspec(dllimport)
    #endif
#else
    #error Little Hazel only support Windows.
#endif