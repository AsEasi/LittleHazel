#pragma once

// LH DLL API :

#ifdef LH_PLATFORM_WINDOWS
    #ifdef LH_BUILD_DLL
        #define LHAZEL_API __declspec(dllexport)
    #else
        #define LHAZEL_API __declspec(dllimport)
    #endif
#else
    #error Little Hazel only support Windows.
#endif

// Bit :

#define BIT(x) (1 << x)

// Assertion :

#ifdef LH_ENABLE_ASSERTS
    #define LH_ASSERT(Condition, ...) \
        {\
            if (!(Condition))\
            {\
                LH_ERROR("Assertion Failed: {0}", __VA_ARGS__);\
                __debugBreak();\
            }\
        }
    #define LH_CORE_ASSERT(Condition, ...) \
        {\
            if (!(Condition))\
            {\
                LH_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);\
                __debugBreak();\
            }\
        }
#else
    #define LH_ASSERT(Condition, ...) 
    #define LH_CORE_ASSERT(Condition, ...) 
#endif

#define LH_BIND_EVENT_FUNCTION(Function) std::bind(&Function, this, std::placeholders::_1)

#include "Log.h"