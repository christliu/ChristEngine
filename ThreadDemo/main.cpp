
// consumer and product
// create thread of windows platform

#include <Windows.h>
#include <iostream>
#include "Mutex.h"

using namespace std;



// @init:
// InitializeCriticalSectionAndSpinCount
// @delete:
// DeleteCriticalSection
// @enter:
// nterCriticalSection
// @eave:
// LeaveCriticalSection

const int MAX_SIZE = 1000;
int buffer[MAX_SIZE];
int startoffset = 0;
int buffersize = 0;
CRITICAL_SECTION bufferLock;
CONDITION_VARIABLE bufferNotEmpty;
CONDITION_VARIABLE bufferNotFull;

bool isRunning = true;

bool isFull()
{
	return buffersize >= MAX_SIZE;
}

bool isEmpty()
{
	return buffersize <= 0;
}


DWORD WINAPI ConsumerFunction(LPVOID lpParam)
{
	int consumerid = int(lpParam);
	while (isRunning)
	{
		EnterCriticalSection(&bufferLock);
		
		while (isEmpty() && isRunning)
		{
			SleepConditionVariableCS(&bufferNotEmpty, &bufferLock, INFINITE);
		}

		if (!isRunning)
		{
			LeaveCriticalSection(&bufferLock);
			break;
		}

		int item = buffer[(startoffset + buffersize) % MAX_SIZE];
		cout << "consume " << consumerid << " index " << startoffset << endl;
		buffersize--;
		startoffset++;
		if (startoffset >= MAX_SIZE)
		{
			startoffset = 0;
		}

		LeaveCriticalSection(&bufferLock);
		WakeConditionVariable(&bufferNotFull);
	}
	
	return 0;
}

DWORD WINAPI ProductFunction(LPVOID lpParam)
{
	while (1)
	{
		EnterCriticalSection(&bufferLock);

		while (isFull() && isRunning)
		{
			SleepConditionVariableCS(&bufferNotFull, &bufferLock, INFINITE);
		}

		if (!isRunning)
		{
			LeaveCriticalSection(&bufferLock);
			break;
		}
		buffer[(startoffset + buffersize) % MAX_SIZE] = 1;
		buffersize++;
		LeaveCriticalSection(&bufferLock);
		WakeConditionVariable(&bufferNotEmpty);

		Sleep(1000);
	}
	return 0;
}

int main()
{
	if (InitializeCriticalSectionAndSpinCount(&bufferLock, 4) == 0)
	{
		ExitProcess(3);
	}

	InitializeConditionVariable(&bufferNotEmpty);
	InitializeConditionVariable(&bufferNotFull);

	HANDLE producer = CreateThread(NULL, 0, ProductFunction, NULL, 0, NULL);
	HANDLE consumer1 = CreateThread(NULL, 0, ConsumerFunction, (PVOID)1, 0, NULL);
	HANDLE consumer2 = CreateThread(NULL, 0, ConsumerFunction, (PVOID)2, 0, NULL);

	cout << "Enter Enter to Exit ..." << endl;
	getchar();

	EnterCriticalSection(&bufferLock);
	isRunning = false;
	LeaveCriticalSection(&bufferLock);

	WakeAllConditionVariable(&bufferNotEmpty);
	WakeAllConditionVariable(&bufferNotFull);

	WaitForSingleObject(producer, INFINITE);
	WaitForSingleObject(consumer1, INFINITE);
	WaitForSingleObject(consumer2, INFINITE);
	
	cout << "All Thread Exit with result " << endl;
	return 0;
}