project "GATE"
    location "GATE"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    defines {
        "GLFW_INCLUDE_NONE"
    }

    files 
    { 
        "src/**.h", 
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        "vendor/GLFW/source/include",
        "vendor/Glad/include",
        "vendor/glm"
    }

    externalincludedirs { 
        "vendor/GLFW/source/include",
        "vendor/Glad/include",
        "vendor/glm"
    }

    libdirs { 
        "bin/" .. outputdir .. "/GATE"
     }

     links
    {
        "OpenGL.framework",
        "GLFW",
        "Glad"
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
