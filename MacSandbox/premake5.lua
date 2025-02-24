project "MacSandbox"
    location "MacSandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    dependson { "GATE", "Glad", "GLFW" } -- Ensure GATE builds first

    files 
    { 
        "src/**.h", 
        "src/**.cpp"
    }

    includedirs
    {
        "../GATE/src",
        "../GATE/vendor/glm",
        "../GATE/vendor/GLFW/source/include",
        "../GATE/vendor/Glad/include",
    }

    externalincludedirs { 
        "../GATE/vendor/glm",
        "../GATE/vendor/GLFW/source/include",
        "../GATE/vendor/Glad/include",
    }

    libdirs { 
        "bin/" .. outputdir .. "/GATE",
        "GATE/vendor/GLFW/bin/" .. outputdir .. "/GLFW"
     }
    links
    {
        "GATE",
        "OpenGL.framework",
        "GLFW",
        "Glad",
        "Cocoa.framework",
        "IOKit.framework",
        "CoreFoundation.framework",
        "CoreVideo.framework",
        "QuartzCore.framework"  -- Add this line to link QuartzCore
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
