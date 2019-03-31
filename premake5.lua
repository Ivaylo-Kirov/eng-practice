workspace "EnginePractice"
	architecture "x64"
	startproject "Sandbox"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "EnginePractice/vendor/GLFW/include"

include "EnginePractice/vendor/GLFW"

project "EnginePractice"
	location "EnginePractice"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "eppch.h"
	pchsource "EnginePractice/src/eppch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links {
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines {
			"EP_PLATFORM_WINDOWS",
			"EP_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "EP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "EP_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include",
		"EnginePractice/src"
	}

	links {
		"EnginePractice"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines {
			"EP_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "EP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "EP_DIST"
		optimize "On"