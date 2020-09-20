#include <iostream>
//#include "TEngine.h"
using namespace std;

namespace TEngine
{
	int __declspec(dllimport) Add(int a, int b);
}

int main()
{
	cout <<"Hello Premake!"<< endl;
	int a = 3, b = 2;
	int c = TEngine::Add(a, b);
	return 0;
}
