project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

    targetdir ("%{wks.location}/Bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/Bin_Int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{wks.location}/%{prj.name}/Source/**.h",
        "%{wks.location}/%{prj.name}/Source/**.cpp",
    }

    includedirs {
        "%{wks.location}/LHazel/Vendor/spdlog@1.13.0/include",
        "%{wks.location}/LHazel/Source",
    }

    links {
        "LHazel"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines {
            "LH_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        symbols "On"
        runtime "Debug"
        defines "LH_DEBUG"

    filter "configurations:Release"
        optimize "On"
        runtime "Release"
        defines "LH_RELEASE"

    filter "configurations:Dist"
        optimize "On"
        runtime "Release"
        defines "LH_DIST"