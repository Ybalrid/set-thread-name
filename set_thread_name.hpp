#pragma once

#include <thread> //std::thread
#include <string_view> //std::string_view

#ifdef WIN32

#ifndef NOMINMAX
#define NOMINMAX
#define NOMINMAX_POP
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN_POP
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#define VC_EXTRALEAN_POP
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS_POP
#endif

#pragma warning(push)
#pragma warning(disable : 4996) //POSIX function unsafe?

#include "windows.h" //Win NT defines
#include "processthreadsapi.h" //SetTrheadDescription()
#include <cstdlib> //std::mbstowcs
#include <vector> //std::vector<wchar_t>

#endif

#ifdef __gnu_linux__
#endif

#ifndef YBA_NS
#define YBA_NS yba
#endif
namespace YBA_NS
{
	void set_name(std::thread& thread, std::string_view thread_name)
	{
#ifdef WIN32
		std::vector<wchar_t> wide_char_string_data(thread_name.size() + 1);
		std::mbstowcs(wide_char_string_data.data(), thread_name.data(), thread_name.size());
		SetThreadDescription(thread.native_handle(), wide_char_string_data.data());
#endif

#ifdef __gnu_linux__
#endif
	}
}
#undef YBA_NS

#ifdef WIN32

#ifdef NOMINMAX_POP
#undef NOMINMAX_POP
#undef NOMINMAX
#endif

#ifdef WIN32_LEAN_AND_MEAN_POP
#undef WIN32_LEAN_AND_MEAN_POP
#undef WIN32_LEAN_AND_MEAN
#endif

#ifdef VC_EXTRALEAN_POP
#undef VC_EXTRALEAN_POP
#undef VC_EXTRALEAN
#endif

#ifdef _CRT_SECURE_NO_WARNINGS_POP
#undef _CRT_SECURE_NO_WARNINGS_POP
#undef _CRT_SECURE_NO_WARNINGS
#endif

#pragma warning (pop)

#endif
