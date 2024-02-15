project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("%{wks.location}/Bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/Bin_Int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{wks.location}/%{prj.name}/Source/**.h",
        "%{wks.location}/%{prj.name}/Source/**.cpp",
    }

    includedirs {
        "%{wks.location}/LHazel/Source",
        "%{IncludeDir.spdlog}",
    }

    links {
        "LHazel"
    }

    filter "system:windows"
        systemversion "latest"

        defines {
            "LH_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        symbols "on"
        runtime "Debug"
        defines "LH_DEBUG"

    filter "configurations:Release"
        optimize "on"
        runtime "Release"
        defines "LH_RELEASE"

    filter "configurations:Dist"
        optimize "on"
        runtime "Release"
        defines "LH_DIST"