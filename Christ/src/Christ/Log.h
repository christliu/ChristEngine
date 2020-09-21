
#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Christ
{
	class CHRIST_API Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLog();
		static std::shared_ptr<spdlog::logger>& GetAppLog();

	private:
		static std::shared_ptr < spdlog::logger > p_CoreLog;
		static std::shared_ptr < spdlog::logger > p_AppLog;
	};
}

#define LOG_INIT Christ::Log::Init();

#define LOG_CORE_TRACE(...) Christ::Log::GetCoreLog()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...) Christ::Log::GetCoreLog()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...) Christ::Log::GetCoreLog()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...) Christ::Log::GetCoreLog()->error(__VA_ARGS__)
#define LOG_CORE_FATAL(...) Christ::Log::GetCoreLog()->fatal(__VA_ARGS__)

#define LOG_TRACE(...) Christ::Log::GetAppLog()->trace(__VA_ARGS__)
#define LOG_INFO(...) Christ::Log::GetAppLog()->info(__VA_ARGS__)
#define LOG_WARN(...) Christ::Log::GetAppLog()->warn(__VA_ARGS__)
#define LOG_ERROR(...) Christ::Log::GetAppLog()->error(__VA_ARGS__)
#define LOG_FATAL(...) Christ::Log::GetAppLog()->fatal(__VA_ARGS__)