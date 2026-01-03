#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace QUA {

	class QUA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//Core log macros
#define QUA_CORE_TRACE(...)  ::QUA::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define QUA_CORE_INFO(...)   ::QUA::Log::GetCoreLogger()->info(__VA_ARGS__)
#define QUA_CORE_WARN(...)   ::QUA::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define QUA_CORE_ERROR(...)  ::QUA::Log::GetCoreLogger()->error(__VA_ARGS__)
#define QUA_CORE_FATAL(...)  ::QUA::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define QUA_TRACE(...)       ::QUA::Log::GetClientLogger()->trace(__VA_ARGS__)
#define QUA_INFO(...)        ::QUA::Log::GetClientLogger()->info(__VA_ARGS__)
#define QUA_WARN(...)        ::QUA::Log::GetClientLogger()->warn(__VA_ARGS__)
#define QUA_ERROR(...)       ::QUA::Log::GetClientLogger()->error(__VA_ARGS__)
#define QUA_FATAL(...)       ::QUA::Log::GetClientLogger()->fatal(__VA_ARGS__)
