#pragma once

#include <queue>
#include <memory>
#include <iostream>
#include <functional>
#include <atomic>

class Task
{
public:
	virtual void Process() = 0;
};


class SimpleTask : public Task
{
public:
	SimpleTask(int base) :m_base(base) {}

	void Process() {
		m_base++;
	}

	int Get()
	{
		return m_base;
	}

private:
	int m_base;
};

template<typename _function>
void addTask(_function fn)
{

}

using FastCallFn = void(*)();

template<typename function>
void AddFunc(function f)
{
	std::cout << "AddFunc Run" << std::endl;
}

template<>
void AddFunc<FastCallFn>(FastCallFn f)
{
	std::cout << "in AddFunc FastCallFn" << std::endl;
}

template<>
void AddFunc<int>(int a)
{
	std::cout << "in AddFunc of Int" << std::endl;
}

//template<typename function>
//typename std::enable_if_t<std::false_type::value, int> AddFunction(function f)
//{
//	std::cout << "in AddFunc of false_type" << std::endl;
//	return 3;
//}

//template<typename function>
//typename std::enable_if_t<std::true_type::value, int> AddFunction(function f)
//{
//	std::cout << "in AddFunc of true_type" << std::endl;
//	return 3;
//}



template<typename _sig> struct callable;

//template<typename _lambda>
//struct callable<void(_lambda::*)()> : public std::true_type {};

template<typename _lambda>
struct callable<void(_lambda::*)()> : public std::true_type {};


template<typename function>
std::enable_if_t<std::is_convertible_v<function, FastCallFn>, int> AddFunction(function f)
{
	std::cout << "in AddFunc of int type " << std::endl;
	return 1;
}

template<typename function>
std::enable_if_t<std::is_convertible_v<function, int>, float> AddFunction(function f)
{
	std::cout << "in AddFunc of float type " << std::endl;
	return 0.1;
}

//template<typename function>
//std::enable_if_t<std::is_convertible_v<function, std::function<void()>>, bool> AddFunction(function f)
//{
//	std::cout << "in AddFunc of bool type" << std::endl;
//	return true;
//}


template<typename function>
std::enable_if_t<
	std::is_convertible_v<function, std::function<void()>> && callable<decltype(&function::operator())>::value,
	double> AddFunction(function f)
{
	std::cout << "in AddFunc of double type" << std::endl;
	return 1L;
}


class FakeFunc
{
public:
	void operator()()
	{

	}
};

void TestUniptr()
{
	std::unique_ptr<Task> ptr(new SimpleTask(3));
	std::queue<std::unique_ptr<Task>> m_queue;
	m_queue.push(std::move(ptr));

	auto task = std::move(m_queue.front());
	task->Process();

	std::cout << "m_base " << static_cast<SimpleTask*>(task.get())->Get() << std::endl;


	auto testfunc = []() {
		std::cout << "In TestFunc" << std::endl;
	};
	
	//AddFunction(testfunc);

	FakeFunc f;
	AddFunction(f);

	std::atomic<int> data{ 0 };

	int com = -1;
	bool res = data.compare_exchange_strong(com, -1);

	std::cout << "after compare exchange strong, res: " << res << " com " << com << " data " << data << std::endl;

	res = data.compare_exchange_strong(com, -1);

	std::cout << "after compare exchange strong, res: " << res << " com " << com << " data " << data << std::endl;
}