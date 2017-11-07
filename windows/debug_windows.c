#include "../common/debug.h"

void debug_log(const char* str)
{
	MessageBox(GetActiveWindow(), str, "Debug Message", MB_OK | MB_ICONINFORMATION);
}

void debug_warn(const char* str)
{
	MessageBox(GetActiveWindow(), str, "Warning Message", MB_OK | MB_ICONEXCLAMATION);
}

void debug_error(const char* str)
{
	MessageBox(GetActiveWindow(), str, "Debug Message", MB_OK | MB_ICONERROR);
}