#pragma once

#ifdef EP_PLATFORM_WINDOWS

	#ifdef EP_BUILD_DLL
		#define EP_API __declspec(dllexport)
	#else
		#define EP_API __declspec(dllimport)
	#endif // EP_BUILD_DLL

#endif // EP_PLATFORM_WINDOWS

#ifdef EP_ENABLE_ASSERTS
	#define EP_ASSERT(x, ...) { if(!(x)) { EP_ERROR(__VA_ARGS__); __debugbreak(); } }
	#define EP_CORE_ASSERT(x, ...) { if(!(x)) { EP_CORE_ERROR(__VA_ARGS__); __debugbreak(); } }
#else
	#define EP_ASSERT(x, ...)
	#define EP_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define EP_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)