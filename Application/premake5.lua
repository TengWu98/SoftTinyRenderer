-- project Application
project "Application"

    -- 项目类型：控制台程序
	kind "ConsoleApp"

    -- 项目语言：C++
	language "C++"

    -- 
	cppdialect "C++17"

    -- 
	staticruntime "on"

    -- 指定输出目录
	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")

    -- 指定中间目录
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    -- 加载src目录下的所有.h,.cpp文件
	files
	{
		"src/**.h",
		"src/**.cpp"
	}

    -- 
	includedirs
	{
		"%{wks.location}/Renderer/src",
        "%{wks.location}/Renderer/vendor",
        "%{wks.location}/Renderer/vendor/spdlog/include",
		"%{IncludeDir.glm}",
	}

  -- 
	links
	{
		"Renderer"
	}

  -- 
	filter "system:windows"
		systemversion "latest"
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