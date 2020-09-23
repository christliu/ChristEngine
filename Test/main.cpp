#include <iostream>
#include <functional>

class Base
{
public:
	virtual void Fun()
	{
		std::cout << "In Base" << std::endl;
	}
	static void F1();
};

class Derived : public Base
{
public:
	virtual void Fun()
	{
		std::cout << "In Derived" << std::endl;
	}

};

void Base::F1()
{
	std::cout << "In F1" << std::endl;
}

bool Dispatch(Base& b)
{
	std::cout << "in Base Dispatch" << std::endl;
	b.Fun();
	return true;
}


template<typename T>
using EventFn = std::function<bool(T&)>;

int main()
{
	std::cout << "Hello Test" << std::endl;

	Derived d;
	//Dispatch(d);

	EventFn<Derived> fn = Dispatch;
	fn(d);

	Derived::F1();

	return 0;
}