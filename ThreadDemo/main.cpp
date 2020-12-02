
// consumer and product
// create thread of windows platform

#include <Windows.h>
#include <iostream>
#include "Mutex.h"

using namespace std;

CRITICAL_SECTION CriticalSection;

// @init:
// InitializeCriticalSectionAndSpinCount
// @delete:
// DeleteCriticalSection
// @enter:
// nterCriticalSection
// @eave:
// LeaveCriticalSection

int result = 0;
const int LOOP_TIMES = 100000;
const int THREAD_NUM = 2;

Mutex m;

DWORD WINAPI MyThreadFunction(LPVOID lpParam)
{
	
	for (int i = 0; i < LOOP_TIMES; i++)
	{
		LockGuard guard(m);
		result++;
	}
	return 0;
}

int main()
{
	HANDLE  hThreadArray[THREAD_NUM];
	for (int i = 0; i < THREAD_NUM; i++)
	{
		hThreadArray[i] = CreateThread(NULL, 0, MyThreadFunction, NULL, 0, NULL);

		if (hThreadArray[i] == NULL)
		{
			cout << "Init Thread Error" << endl;
			ExitProcess(3);
		}
	}
	WaitForMultipleObjects(THREAD_NUM, hThreadArray, true, INFINITE);
	
	cout << "All Thread Exit with result " << result << endl;
	return 0;
}