#include<iostream>
int main(void)
{
	int a=10;
	int &b=a;
	std::cout<<" a = "<<a<<std::endl;
	b=20;
	std::cout<<" a = "<<a<<std::endl;
}
