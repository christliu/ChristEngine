workspace "TEngine"
	architecture "x86_64"
	configurations {"Debug", "Release"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "TEngine"
	location "TEngine"
	kind "SharedLib"
	language "c++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
	}

	filter "system:windows"
		systemversion "latest"
		defines
		{
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Game")
		}
	

project "Game"
	location "Game"
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
		"TEngine"
	}

	includedirs
	{
		"TEngine/src",
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"
		defines
		{
		}
	
