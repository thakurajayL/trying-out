#include<iostream>

int j=4;
int main()
{
	int j=10;
	std::cout<<"\n J="<<j<<std::endl;
	{
		int j=20;
		std::cout<<"\n Local J="<<j<<std::endl;
		std::cout<<"\n Global ::J = "<<::j<<std::endl;  // global j is referred.. 4 in this example
	}
	std::cout<<"\n";
	return 0;
}
