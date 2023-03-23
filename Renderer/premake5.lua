-- project Renderer
project "Renderer"

    -- 项目类型：静态链接库
	kind "ConsoleApp"

    -- 语言：C++
	language "C++"

    -- 
	cppdialect "C++17"

    -- 
	staticruntime "on"

    -- 指定输出目录
	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")

    -- 指定中间目录
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    -- 
	pchheader "pch.h"

    -- 
	pchsource "src/pch.cpp"

  
	files
	{
        -- 加载src目录下的所有.h,.cpp文件
		"src/**.h",
		"src/**.cpp",

        -- 加载stb_image目录下的所有.h,.cpp文件
        "vendor/stb_image/**.h",
		"vendor/stb_image/**.cpp",

		-- 加载glm相关源文件
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl",
	}

  	-- 
	includedirs
	{
    	--
		"src",

    	-- 日志
    	"vendor/spdlog/include",
        -- stb_image
        "%{IncludeDir.stb_image}",
		-- glm数学库
		"%{IncludeDir.glm}",
	}
  
	-- 
	flags { "NoPCH" }

	-- 当前系统是windows时
	filter "system:windows"
		systemversion "latest"
        -- 
		defines
		{
			"RENDERER_PLATFORM_WINDOWS",
			"RENDERER_ENABLE_ASSERTS"
		}

	-- Debug配置项属性
	filter "configurations:Debug"
		defines "RENDERER_DEBUG"
		runtime "Debug"
		-- 开启调试符号
		symbols "on"

	-- Release配置项属性
	filter "configurations:Release"
		defines "RENDERER_RELEASE"
		runtime "Release"
		-- 开启优化参数
		optimize "on"

	-- Dist配置项属性
	filter "configurations:Dist"
		defines "RENDERER_DIST"
		runtime "Release"
		-- 开启优化参数
		optimize "on"