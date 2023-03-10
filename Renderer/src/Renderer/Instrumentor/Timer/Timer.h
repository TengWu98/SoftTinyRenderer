#pragma once
#include <chrono>
#include <iomanip>
#include <thread>
#include <mutex>

RENDERER_NAMESPACE_BEGIN

using FloatingPointMicroseconds = std::chrono::duration<double, std::micro>;

class Timer
{
public:
	// 构造函数
	Timer(const std::string& sName);
	// 析构函数
	~Timer();
private:
	void Stop();
private:
	std::string m_sName;
	bool m_bStopped;
	std::chrono::time_point<std::chrono::steady_clock> m_spStartTimepoint;
};

RENDERER_NAMESPACE_END

#define RENDERER_PROFILE_SCOPE(sName) ::Renderer::Timer timer##__LINE__(sName);
#define RENDERER_PROFILE_FUNCTION() RENDERER_PROFILE_SCOPE(__FUNCSIG__)