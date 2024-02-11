project "LHazel"
    kind "SharedLib"
    language "C++"

    targetdir ("%{wks.location}/Bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/Bin_Int/" .. outputdir .. "/%{prj.name}")
    
    pchheader "LHPCH.h"
    pchsource "%{wks.location}/%{prj.name}/Source/LHPCH.cpp"

    files {
        "%{wks.location}/%{prj.name}/Source/**.h",
        "%{wks.location}/%{prj.name}/Source/**.cpp",
    }

    includedirs {
        "%{wks.location}/%{prj.name}/Source",
        "%{wks.location}/%{prj.name}/Vendor/spdlog@1.13.0/include",
        "%{IncludeDir.GLFW}",
    }

    links {
        "GLFW",
        "opengl32.lib",
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "LH_PLATFORM_WINDOWS",
            "LH_BUILD_DLL",
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        symbols "On"
        staticruntime "off"
        runtime "Debug"
        defines "LH_DEBUG"

    filter "configurations:Release"
        optimize "On"
        staticruntime "off"
        runtime "Release"
        defines "LH_RELEASE"

    filter "configurations:Dist"
        optimize "On"
        staticruntime "off"
        runtime "Release"
        defines "LH_DIST"