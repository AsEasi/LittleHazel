-- premake5.lua

include "Dependencies.lua"

workspace "LittleHazel"
    architecture "x86_64"
    startproject "Sandbox"

    configurations {
        "Debug",
        "Release",
        "Dist",
    }

outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"

group "Dependencies"
    include "LHazel/Vendor/GLFW@3.3.9"
    include "LHazel/Vendor/Glad@0.1.36"
    include "LHazel/Vendor/ImGui-docking@1.90.2"
group ""

include "LHazel"
include "Sandbox"