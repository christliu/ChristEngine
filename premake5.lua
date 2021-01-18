workspace "ChristEngine"
	architecture "x86_64"
	configurations {"Debug", "Release"}
	characterset "MBCS"

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


include "Christ/external/imgui"
include "Christ/external/glad"


project "TestGlad"
	location "TestGlad"
	kind "WindowedApp"
	language "c++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/TestGlad.cpp",
	}

	includedirs {
		"Christ/external/glad/include"
	}

	links {
		"glad",
		"opengl32.lib"
	}
	

project "Test"
	location "Test"
	kind "WindowedApp"
	language "c++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		-- "%{prj.name}/**.h",
		-- "%{prj.name}/**.cpp"
		"%{prj.name}/TestImGui.cpp",
		"%{prj.name}/wglext.h",
		"Christ/external/imgui/examples/imgui_impl_win32.cpp",
		"Christ/external/imgui/examples/imgui_impl_opengl3.cpp",
		"Christ/external/imgui/examples/libs/gl3w/GL/gl3w.c",

	}

	includedirs
	{
		"Christ/external/imgui",
		-- "Christ/external/imgui/examples",
		"Christ/external/imgui/examples/libs/gl3w"
	}

	links
	{
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"
		defines
		{
		}


project "ThreadDemo"
	location "ThreadDemo"
	kind "ConsoleApp"
	language "c++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	-- includedirs
	-- {
	-- 	"%{prj.name}/",
	-- }

	files {
		"%{prj.name}/main.cpp",
		"%{prj.name}/Mutex.h",
		"%{prj.name}/TaskDispatcher.h",
	}

	