#include<iostream>
#include<iomanip>
using namespace std;
int main (void)
{
	cout<<" Without setw"<<endl;
	cout<< 500<<endl;
	cout<<10000<<endl;
	cout<<" With setw"<<endl;
	cout<<setw(5)<< 500<<endl;
	cout<<setw(5)<<10000<<endl;
	return 1;
}
