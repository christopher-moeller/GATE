project "GATE"
    location "GATE"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "src/**.h", 
        "src/**.cpp",
        "src/**.mm"
    }

    includedirs
    {
        "src"
    }


    filter "system:macosx"
        defines { "GATE_PLATFORM_MACOS" }

    filter "system:windows"
        defines { "GATE_PLATFORM_WINDOWS" }
        systemversion "latest"

    filter "configurations:Debug"
        defines { "GATE_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "GATE_RELEASE" }
        optimize "On"

    filter "configurations:Dist"
        defines { "GATE_DIST" }
        optimize "On"
