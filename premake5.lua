workspace "GATE"
    platforms { "x64" }

    configurations
    { 
        "Debug", 
        "Release",
        "Dist" 
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}"

project "GATE"
    location "GATE"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
    }

    filter "system:macosx"
        defines { "GATE_PLATFORM_MACOS" }
    
    filter "configurations:Debug"
        defines { "GATE_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "GATE_RELEASE" }
        optimize "On"

    filter "configurations:Dist"
        defines { "GATE_DIST" }
        optimize "On"



project "MacSandbox"
    location "MacSandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "GATE/src"
    }

    libdirs { 
        "bin/" .. outputdir .. "/GATE"
     }
    links
    {
        "GATE",
    }

    filter "system:macosx"
        defines { "GATE_PLATFORM_MACOS" }
    
    filter "configurations:Debug"
        defines { "GATE_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "GATE_RELEASE" }
        optimize "On"

    filter "configurations:Dist"
        defines { "GATE_DIST" }
        optimize "On"