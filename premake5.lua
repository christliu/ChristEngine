workspace "ChristEngine"
	architecture "x86_64"
	configurations {"Debug", "Release"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Christ"
	location "Christ"
	kind "SharedLib"
	language "c++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "Pch.h"
	pchsource "Christ/src/Pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/external/spdlog/include",
	}

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"
		defines
		{
			"CHRIST_BUILD"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/GameApp")
		}
	

project "GameApp"
	location "GameApp"
	kind "ConsoleApp"
	language "c++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"
	}

	links
	{
		"Christ"
	}

	includedirs
	{
		"Christ/src",
		"Christ/external/spdlog/include",
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"
		defines
		{
		}
	
