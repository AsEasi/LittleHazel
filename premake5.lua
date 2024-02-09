-- premake5.lua

workspace "LittleHazel"
    architecture "x86_64"
    startproject "Sandbox"

    configurations {
        "Debug",
        "Release",
        "Dist",
    }

outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"

project "LHazel"
    location "LHazel"
    kind "SharedLib"
    language "C++"

    targetdir ("%{wks.location}/Bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Bin_Int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp",
    }

    includedirs {
        "%{prj.name}/Vendor/spdlog@1.13.0/include"
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

        defines {
            "LH_DEBUG",
        }

    filter "configurations:Release"
        optimize "On"

        defines {
            "LH_RELEASE",
        }

    filter "configurations:Dist"
        optimize "On"

        defines {
            "LH_DIST",
        }

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("%{wks.location}/Bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/Bin_Int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp",
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
        staticruntime "On"
        systemversion "latest"

        defines {
            "LH_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        symbols "On"

        defines {
            "LH_DEBUG",
        }

    filter "configurations:Release"
        optimize "On"

        defines {
            "LH_RELEASE",
        }

    filter "configurations:Dist"
        optimize "On"

        defines {
            "LH_DIST",
        }