#include <iostream>

class Base 
{
	public:
		virtual ~Base()
		{
			std::cout<<"Base class destructor\n";
		}
};

class Derived:public Base
{
	public:
		~Derived()
		{
			std::cout<<"Derived class destructor\n";
		}
};

int main()
{
	Base *b = new Derived;
	delete b;
	return 0;
}
