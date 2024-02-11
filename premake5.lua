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

include "LHazel/Vendor/GLFW@3.3.9"

include "LHazel"
include "Sandbox"