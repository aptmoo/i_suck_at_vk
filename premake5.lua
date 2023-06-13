workspace "vklearn"
    configurations { "Debug", "Release" }

project "App"
    -- Input
    files
    {
        "src/**.h", "src/**.cpp"
    }

    includedirs
    {
        "src/"
    }

    -- Preprocessor
    defines { "GLFW_INCLUDE_NONE" }

    -- Linker
    links {  }

    filter { "system:linux" }
        links { "vulkan", "dl", "m", "glfw", "pthread", "X11", "Xrandr", "Xi" }
        libdirs { "/usr/bin" }
    filter {}

    -- Language
    language    "C++"
    cppdialect  "C++17"

    -- Output
    targetname  "VkApp"
    targetdir   "bin/"
    objdir      "bin-int/"
    kind        "ConsoleApp"

    -- Config 
    filter { "configurations:Debug" }
        defines { "DEBUG" }
        symbols "On"

    filter { "configurations:Release" }
        defines { "NDEBUG" }
        optimize "On"