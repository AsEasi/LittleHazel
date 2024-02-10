#include "LHPCH.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace LHazel
{

    std::shared_ptr<spdlog::logger> Log::_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::_ClientLogger;

    void Log::Init()
    {
        // Init logger pattern.
        spdlog::set_pattern("%^[%T] %n: %v%$");

        // Init core logger.
        _CoreLogger = spdlog::stdout_color_mt("LHAZEL");
        _CoreLogger -> set_level(spdlog::level::trace);

        // Init client logger.
        _ClientLogger = spdlog::stdout_color_mt("APPLICATION");
        _ClientLogger -> set_level(spdlog::level::trace);
    }

}