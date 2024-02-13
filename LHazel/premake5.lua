project "LHazel"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

    targetdir ("%{wks.location}/Bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/Bin_Int/" .. outputdir .. "/%{prj.name}")
    
    pchheader "LHPCH.h"
    pchsource "%{wks.location}/%{prj.name}/Source/LHPCH.cpp"

    files {
        "%{wks.location}/LHazel/Source/**.h",
        "%{wks.location}/LHazel/Source/**.cpp",
		"%{wks.location}/LHazel/Vendor/GLM@1.0.0/**.hpp",
		"%{wks.location}/LHazel/Vendor/GLM@1.0.0/**.inl",
    }

    includedirs {
        "%{wks.location}/%{prj.name}/Source",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.GLM}",
    }

    links {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib",
    }

    filter "system:windows"
        cppdialect "C++17"
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