
baseName = path.getbasename(os.getcwd());

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["box2d"] = "../Quaternion/external/box2d/include"
include "../Quaternion/external/box2d"

project "Quaternion"
  	kind "SharedLib"
    location "../Quaternion"
	language "C++"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "../Quaternion/src/pch.cpp"

	filter "configurations:Debug"
		defines "QUA_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "QUA_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "QUA_DIST"
		buildoptions "/MD"
		optimize "On"

    filter "configurations:Release"
		kind "WindowedApp"
		entrypoint "mainCRTStartup"

	filter "action:vs*"
        debugdir "$(SolutionDir)"
		
	filter {"action:vs*", "configurations:Release"}
			kind "WindowedApp"
			entrypoint "mainCRTStartup"
	filter {}


    files
	{
		"../%{prj.name}/src/**.h",
		"../%{prj.name}/src/**.cpp"
	}

    includedirs 
	{ 
		"./", "src",
		"../Quaternion/external/spdlog/include",
		"%{IncludeDir.box2d}"
	}
	links
	{
		"box2d"
	}
	link_raylib();
	
	-- To link to a lib use link_to("LIB_FOLDER_NAME")

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"QUA_PLATFORM_WINDOWS",
			"QUA_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Game")
		}

	buildoptions { "/utf-8" }

project "Game"
	location "../Game"
	kind "ConsoleApp"
	language "C++"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"../%{prj.name}/src/**.h",
		"../%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"../Quaternion/external/spdlog/include",
		"../Quaternion/src"
		
	}

	links
	{
		"Quaternion"
	}

	buildoptions { "/utf-8" }

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"QUA_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "QUA_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "QUA_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "QUA_DIST"
		buildoptions "/MD"
		optimize "On"


	