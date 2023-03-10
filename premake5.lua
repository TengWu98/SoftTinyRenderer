-- Renderer Dependencies
IncludeDir = {}
-- 图像解码库
IncludeDir["stb_image"] = "%{wks.location}/Renderer/vendor/stb_image"
-- GLFW库
IncludeDir["GLFW"] = "%{wks.location}/Renderer/vendor/GLFW/include"
-- 数学库
IncludeDir["glm"] = "%{wks.location}/Renderer/vendor/glm"
-- IncludeDir["yaml_cpp"] = "%{wks.location}/TinyEngine/vendor/yaml-cpp/include"
-- IncludeDir["GL3W"] = "%{wks.location}/TinyEngine/vendor/GL3W/include"
-- IncludeDir["ImGui"] = "%{wks.location}/TinyEngine/vendor/ImGui"
-- IncludeDir["ImGuizmo"] = "%{wks.location}/TinyEngine/vendor/ImGuizmo"

-- IncludeDir["entt"] = "%{wks.location}/TinyEngine/vendor/entt/include"
-- IncludeDir["Box2D"] = "%{wks.location}/TinyEngine/vendor/Box2D/include"
-- IncludeDir["mono"] = "%{wks.location}/TinyEngine/vendor/mono/include"

-- LibraryDir = {}
-- LibraryDir["mono"] = "%{wks.location}/TinyEngine/vendor/mono/lib/%{cfg.buildcfg}"

-- Library = {}
-- Library["mono"] = "%{LibraryDir.mono}/mono-2.0-sgen.lib"

-- BinaryDir = {}
-- BinaryDir["mono"] = "%{wks.location}/TinyEngine/vendor/mono/bin/%{cfg.buildcfg}"

-- Binary = {}
-- Binary["mono"] = "%{BinaryDir.mono}/mono-2.0-sgen.dll"

--workspace 解决方案
workspace "SoftwareRenderer"

  -- 启动项目
  startproject "Application"

  -- 解决方案配置项：Debug、Release、Dist
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

  -- 平台配置
  platforms
  {
    'x64',
    
  }

  -- x64平台配置属性
  filter "platforms:x64"
    -- 指定架构为x64
    architecture "x64"

  -- 指定输出目录和中间目录的文件夹名称
  outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

  group "Dependencies"
    include "Renderer/vendor/GLFW"
  group ""

  group "Renderer"
    include "Renderer"
  group ""

  group "Application"
    include "Application"
  group ""

