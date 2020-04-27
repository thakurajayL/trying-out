#include<iostream>

namespace first
{
	int a;
	int b;
}

namespace second
{
	double a;
	double b;
}

int main()
{
	first::a=2;
	first::b=4;

	second::a=2.3;
	second::b=4.2;
	std::cout<<first::a+second::a<<std::endl;
	std::cout<<first::b+second::b<<std::endl;
	return 0;
}

