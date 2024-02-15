project "LHazel"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

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