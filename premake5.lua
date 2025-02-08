workspace "GATE"
    platforms { "x64" }

    configurations
    { 
        "Debug", 
        "Release",
        "Dist" 
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "GATE"
include "MacSandbox"