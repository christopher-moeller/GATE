project "GLFW"
    kind "StaticLib"
    language "C"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "source/include/GLFW/**.h",
        "source/src/**.c",
        "source/src/**.m"
    }

    filter "system:macosx"
        systemversion "latest"
        defines { "_GLFW_COCOA" }  

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
