#include<iostream>
using namespace std;
class fun
{
	int i,j;
	char name[10];
	public:
		void getdata(void)
		{
			cout<<" Enter 2 numbers"<<endl;
			cin>>i>>j;
		}
		void display(void)
		{
			cout<<"i= "<<i<<"; j= "<<j<<endl;
		}
		void add( fun, fun);
};
void fun :: add (fun A, fun B)
{
	i= A.i + B.i;
	j= A.j + B.j;
}
int main (void)
{
	fun A,B,C;
	A.getdata();
	A.display();
	B.getdata();
	B.display();
	C.add(A,B);
	cout<<"display C"<<endl;
	C.display();
	return 0;
}
