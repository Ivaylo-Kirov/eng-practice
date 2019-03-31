#pragma once
#include "eppch.h"
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace EnginePractice {
	class EP_API Log
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


// CORE LOG MACROS
#define EP_CORE_TRACE(...) ::EnginePractice::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EP_CORE_INFO(...)  ::EnginePractice::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EP_CORE_WARN(...)  ::EnginePractice::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EP_CORE_ERROR(...) ::EnginePractice::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EP_CORE_FATAL(...) ::EnginePractice::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// CLIENT LOG MACROS
#define EP_TRACE(...)      ::EnginePractice::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EP_INFO(...)       ::EnginePractice::Log::GetClientLogger()->info(__VA_ARGS__)
#define EP_WARN(...)       ::EnginePractice::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EP_ERROR(...)      ::EnginePractice::Log::GetClientLogger()->error(__VA_ARGS__)
#define EP_FATAL(...)      ::EnginePractice::Log::GetClientLogger()->fatal(__VA_ARGS__)