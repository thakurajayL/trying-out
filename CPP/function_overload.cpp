#include<iostream>
using namespace std;
int mul(int i)
{
	return 2*i;
}
float mul(float i)
{
	return 2*i;
}

int main(void)
{
	int i=2,j;
	float k=3.4,l;
	j=mul(i);
	cout<<j<<endl;
	l=mul(k);
	cout<<l<<endl;
}
