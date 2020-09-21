#pragma once

#ifdef CHRIST_BUILD
#define CHRIST_API __declspec(dllexport)
#else
#define CHRIST_API __declspec(dllimport)
#endif