#pragma once

#ifdef EP_PLATFORM_WINDOWS

	#ifdef EP_BUILD_DLL
		#define EP_API __declspec(dllexport)
	#else
		#define EP_API __declspec(dllimport)
	#endif // EP_BUILD_DLL

#endif // EP_PLATFORM_WINDOWS
