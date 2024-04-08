workspace "R"
	architecture "x64"
	startproject "R"

	configurations
	{
		"Debug",
		"Release"
	}

local tempPath = _MAIN_SCRIPT_DIR .. "/"

-- OUTPUT DIRECTORIES
OutDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/"
BinDir = tempPath .. "Build/Bin/" .. OutDir
IntDir = tempPath .. "Build/Intermediates/" .. OutDir

-- EXTERNAL DEPENCENCIES DIR
ExtDep = "ED"

-- INCLUDE DIRECTORIES
IncludeDir = {}

group "Apps"
	include "R/Source"
