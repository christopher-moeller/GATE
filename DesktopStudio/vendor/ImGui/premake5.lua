project "ImGui"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir "bin/%{cfg.buildcfg}/ImGui"
    objdir "bin-int/%{cfg.buildcfg}/ImGui"

    dependson { "GLFW" }

    files {
        "ImGui/imconfig.h",
		"ImGui/imgui.h",
		"ImGui/imgui.cpp",
		"ImGui/imgui_draw.cpp",
		"ImGui/imgui_internal.h",
		"ImGui/imgui_widgets.cpp",
		"ImGui/imstb_rectpack.h",
		"ImGui/imstb_textedit.h",
		"ImGui/imstb_truetype.h",
		"ImGui/imgui_demo.cpp",
        "ImGui/imgui_tables.cpp",
        "ImGui/backends/imgui_impl_glfw.cpp",
        "ImGui/backends/imgui_impl_opengl3.cpp"
    }

    includedirs {
        "../../../GATE/vendor/GLFW/source/include",       -- Needed for imgui_impl_glfw
    }

    externalincludedirs { "../../../GATE/vendor/GLFW/source/include"  } -- This is needed for XCode