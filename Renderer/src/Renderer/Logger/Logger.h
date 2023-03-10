#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

RENDERER_NAMESPACE_BEGIN

// 日志类（单例模式）
class Logger
{
public:
	static Ref<spdlog::logger> GetLogger();
private:
	// 单例模式，删除默认构造，拷贝构造，赋值运算符重载
	Logger() = delete;
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;
private:
	// spdlog日志
	static Ref<spdlog::logger> m_spLogger;
};

RENDERER_NAMESPACE_END

#define LOG_DEV_ERROR(...) ::Renderer::Logger::GetLogger()->error(__VA_ARGS__)

#define LOG_DEV_WARN(...) ::Renderer::Logger::GetLogger()->warn(__VA_ARGS__)

#define LOG_DEV_INFO(...) ::Renderer::Logger::GetLogger()->info(__VA_ARGS__)

#define LOG_DEV_TRACE(...) ::Renderer::Logger::GetLogger()->trace(__VA_ARGS__)