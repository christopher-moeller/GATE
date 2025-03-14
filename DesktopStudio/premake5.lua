project "DesktopStudio"
    location "DesktopStudio"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    dependson { "GATE", "Glad", "GLFW" }

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

    libdirs { 
        "bin/" .. outputdir .. "/GATE",
        "GATE/vendor/GLFW/bin/" .. outputdir .. "/GLFW"
     }
    links
    {
        "GATE",
        "GLFW",
        "Glad"
    }

    filter "system:macosx"
        defines { "GATE_PLATFORM_MACOS" }

        externalincludedirs 
        { 
            "../GATE/vendor/glm",
            "../GATE/vendor/GLFW/source/include",
            "../GATE/vendor/Glad/include",
        }

        links
        {
            "OpenGL.framework",
            "Cocoa.framework",
            "IOKit.framework",
            "CoreFoundation.framework",
            "CoreVideo.framework",
            "QuartzCore.framework"
        }

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
