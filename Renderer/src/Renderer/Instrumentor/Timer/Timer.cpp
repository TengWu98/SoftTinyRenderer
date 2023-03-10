#include "pch.h"
#include "Timer.h"

RENDERER_NAMESPACE_BEGIN
Timer::Timer(const std::string& sName) :m_sName(sName), m_bStopped(false)
{
	m_spStartTimepoint = std::chrono::steady_clock::now();
}

Timer::~Timer()
{
	if (!m_bStopped)
		Stop();
}

void Timer::Stop()
{
	auto spEndTimepoint = std::chrono::steady_clock::now();
	auto highResStart = FloatingPointMicroseconds{ m_spStartTimepoint.time_since_epoch() };
	auto elapsedTime = std::chrono::time_point_cast<std::chrono::microseconds>(spEndTimepoint).time_since_epoch() -
		std::chrono::time_point_cast<std::chrono::microseconds>(m_spStartTimepoint).time_since_epoch();

	// Instrumentor::GetInstrumentor()->WriteProfile({ m_sName, highResStart, elapsedTime, std::this_thread::get_id() });

	m_bStopped = true;
}

RENDERER_NAMESPACE_END