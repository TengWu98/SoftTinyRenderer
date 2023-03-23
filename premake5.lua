-- Renderer Dependencies
IncludeDir = {}
-- 图像解码库
IncludeDir["stb_image"] = "%{wks.location}/Renderer/vendor/stb_image"
-- 数学库
IncludeDir["glm"] = "%{wks.location}/Renderer/vendor/glm"

--workspace 解决方案
workspace "SoftwareRenderer"

  -- 启动项目
  startproject "Renderer"

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
    'x86',
    'x64',
  }
    -- x32平台配置属性
    filter "platforms:x86"
    -- 指定架构为x32
    architecture "x86"
    characterset ("MBCS")

  -- x64平台配置属性
  filter "platforms:x64"
    -- 指定架构为x64
    architecture "x64"
    characterset ("MBCS")

  -- 指定输出目录和中间目录的文件夹名称
  outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

  group "Renderer"
    include "Renderer"
  group ""

