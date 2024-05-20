#pragma once

#ifdef RACING_DYNAMIC_LIBRARY_EXPORT
#define RACING_DYNAMIC_LIBRARY_API __declspec(dllexport)
#else
#define RACING_DYNAMIC_LIBRARY_API __declspec(dllimport)
#endif 

class Air
{
protected:
	int speed;
};