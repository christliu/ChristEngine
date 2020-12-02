#pragma once

#include <Windows.h>

class Mutex
{
public:
	Mutex()
	{
		if (InitializeCriticalSectionAndSpinCount(&m_CriticalSection, 4) == 0)
		{
			ExitProcess(3);
		}
	};
	~Mutex()
	{
		DeleteCriticalSection(&m_CriticalSection);
	};

	void Lock()
	{
		EnterCriticalSection(&m_CriticalSection);
	};
	void UnLock()
	{
		LeaveCriticalSection(&m_CriticalSection);
	};

private:
	CRITICAL_SECTION m_CriticalSection;
};


class LockGuard
{
public:
	LockGuard(Mutex& m) :m_mutex(m) { m_mutex.Lock(); };
	~LockGuard()
	{
		m_mutex.UnLock();
	}

private:
	// disable copy and assign
	LockGuard(const LockGuard&);
	void operator=(const LockGuard&);

private:
	Mutex& m_mutex;
};