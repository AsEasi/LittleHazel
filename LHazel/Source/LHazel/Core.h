#pragma once

#ifdef LH_PLATFORM_WINDOWS
#else
    #error Little Hazel only support Windows.
#endif

// Bit macro :

#define BIT(x) (1 << x)

// Assertion :

#ifdef LH_DEBUG
    #define LH_ENABLE_ASSERTS
#endif

#ifdef LH_ENABLE_ASSERTS
    #define LH_ASSERT(Condition, ...) \
        {\
            if (!(Condition))\
            {\
                LH_ERROR("Assertion Failed: {0}", __VA_ARGS__);\
                __debugbreak();\
            }\
        }
    #define LH_CORE_ASSERT(Condition, ...) \
        {\
            if (!(Condition))\
            {\
                LH_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);\
                __debugbreak();\
            }\
        }
#else
    #define LH_ASSERT(Condition, ...) 
    #define LH_CORE_ASSERT(Condition, ...) 
#endif

// Bind event function macro :

#define LH_BIND_EVENT_FUNCTION(Function) std::bind(&Function, this, std::placeholders::_1)

// Often used headers :

#include "LHazel/Log/Log.h"