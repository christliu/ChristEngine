
#include "Log.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Christ
{
	std::shared_ptr < spdlog::logger > Log::p_CoreLog;
	std::shared_ptr < spdlog::logger > Log::p_AppLog;

	void Log::Init()
	{
		p_CoreLog = spdlog::stdout_color_mt("Christ");
		p_CoreLog->set_level(spdlog::level::trace);
		p_AppLog = spdlog::stdout_color_mt("Application");
		p_AppLog->set_level(spdlog::level::trace);
	}

	std::shared_ptr<spdlog::logger>& Log::GetCoreLog()
	{
		return Log::p_CoreLog;
	}

	std::shared_ptr<spdlog::logger>& Log::GetAppLog()
	{
		return Log::p_AppLog;
	}
}