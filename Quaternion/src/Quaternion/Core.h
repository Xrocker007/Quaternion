#pragma once

#ifdef QUA_PLATFORM_WINDOWS
	#ifdef QUA_BUILD_DLL
		#define QUA_API __declspec(dllexport)
	#else
		#define QUA_API __declspec(dllimport)
	#endif
#else
	#error Quaternion only supports windows
#endif

#ifdef QUA_ENABLE_ASSERTS
	#define QUA_ASSERT(x, ...) { if(!(x)) { QUA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } } 
	#define QUA_CORE_ASSERT(x, ...) { if(!(x)) { QUA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } } 
#else
	#define QUA_ASSERT(x, ...)
	#define QUA_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)