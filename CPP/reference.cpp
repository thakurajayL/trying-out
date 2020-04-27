#include<iostream>
using namespace std;
void change(int &t)
{
	t=10;
}
int &variable(int &a,int &b)
{
	if(a>b)
		return a;
	else
		return b;
}
int b=8;
main()
{
	int n=9;
	cout<<"before calling change n="<<n<<endl;
	change(n);//call by reference
	cout<<"after calling change n="<<n<<endl;
	cout<<"before going inside the hook"<<endl;
	int b=6;
	cout<<"local value of b="<<b<<endl;
	cout<<"global value of b="<<::b<<endl;
	int &c=b;//after this expression c & d are same variable
	c=12;
	cout<<"the value of b is changed to b="<<b<<endl;
	cout<<"the value of b before calling function="<<b<<endl;
	cout<<"the value of n before calling function="<<n<<endl;
	variable(n,b)=3;//this line will assign 10 to variable which has grater value
	cout<<"the value of b after calling function="<<b<<endl;
	cout<<"the value of n after calling function="<<n<<endl;
	return 0;
	
}
