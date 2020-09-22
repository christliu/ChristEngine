#include <iostream>
#include <functional>

class Base
{
public:
	virtual void Fun()
	{
		std::cout << "In Base" << std::endl;
	}

};

class Derived : public Base
{
public:
	virtual void Fun()
	{
		std::cout << "In Derived" << std::endl;
	}

};

bool Dispatch(Base& b)
{
	std::cout << "in Base Dispatch" << std::endl;
	b.Fun();
	return true;
}

//bool Dispatch(Derived& b)
//{
//	std::cout << "In Derived Dispatch " << std::endl;
//	b.Fun();
//	return true;
//}

template<typename T>
using EventFn = std::function<bool(T&)>;

int main()
{
	std::cout << "Hello Test" << std::endl;

	Derived d;
	//Dispatch(d);

	EventFn<Derived> fn = Dispatch;
	fn(d);

	return 0;
}