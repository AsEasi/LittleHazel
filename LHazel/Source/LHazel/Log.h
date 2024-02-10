#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace LHazel
{

    class LHAZEL_API Log
    {
    public:

        static void Init();

        inline static std::shared_ptr<spdlog::logger> GetCoreLogger() { return _CoreLogger; }
        inline static std::shared_ptr<spdlog::logger> GetClientLogger() { return _ClientLogger; }

    private:

        static std::shared_ptr<spdlog::logger> _CoreLogger;
        static std::shared_ptr<spdlog::logger> _ClientLogger;
    };

}

// Core logger macros
#define LH_CORE_TRACE(...)      ::LHazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LH_CORE_INFO(...)       ::LHazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LH_CORE_WARN(...)       ::LHazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LH_CORE_ERROR(...)      ::LHazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LH_CORE_CRITICAL(...)   ::LHazel::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client logger macros
#define LH_TRACE(...)           ::LHazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LH_INFO(...)            ::LHazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define LH_WARN(...)            ::LHazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LH_ERROR(...)           ::LHazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define LH_CRITICAL(...)        ::LHazel::Log::GetClientLogger()->critical(__VA_ARGS__)