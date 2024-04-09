project "R"
	debugdir "%{tempPath}"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetdir (BinDir  .. "/%{prj.name}")
	objdir (IntDir .. "/%{prj.name}")

	files
	{
        "**.cpp",
		"**.h"
	}

	includedirs
	{
		"%{IncludeDir.glm}",
	}

	filter "system:windows"
		systemversion "latest"
		
		defines
		{

		}


	filter "configurations:Debug"
		
		defines
		{
		}
		runtime "Debug"
		symbols "on"
		

	filter "configurations:Release"
		
		defines
		{
		}
		runtime "Release"
		optimize "on"