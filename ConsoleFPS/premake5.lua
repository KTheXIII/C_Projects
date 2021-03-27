project "ConsoleFPS" -- Set the project name
    kind "ConsoleApp"
    language "C"
    staticruntime "on"
    cdialect "C11"

    targetdir("%{wks.location}/bin/%{cfg.buildcfg}/%{prj.name}")
    objdir("%{wks.location}/obj/%{cfg.buildcfg}/%{prj.name}")

    files {
        "src/**.h",
        "src/**.c",
    }

    includedirs {
        "src",
        TERMINAL_INCLUDE
    }

    defines {
        -- Define here
    }

    libdirs {
        -- lib directory 
    }

    links {
        -- link library here
        "Terminal"
    }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"

    filter "system:macosx"
        systemversion "latest"
        system "macosx"

        links {
            "ncurses"
        }
    
    filter "system:linux"
        system "linux"
        systemversion "latest"

        links {
            "ncurses"
        }
    
    filter "system:Windows"
        system "Windows"
        systemversion "latest"
