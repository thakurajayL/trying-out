//this is circular queue implementation using array 
//problem with the exceptional handling
#include<iostream>
#include<stdlib.h>
#define max 5 

using namespace std;

class queue
{
		static int size,head;
		int a[max];
	public:
		void ele_delete(void);
		int ele_add(void);
		queue(void);
		void display(void);
};
int queue :: size;
int queue :: head;
queue::queue(void)
{
	size=0;
	head=0;
}
void queue ::display(void)
{
	cout<<"Numbers :"<<endl;
	for(int i=0;i<size;i++)
	cout<<a[(i+head)%max]<<endl;
}
int queue ::ele_add(void)
{
	try
	{
		if(size==max)
		{
			cout<<"found !!!!!"<<endl;
			throw "queue is full";
			
		}
		else
		{
			cout<<"Enter number "<<endl;
			int add=(head+size)%max;
			cin>>a[add];
			if(size==0)
				head=0;
			size++;
		}
	}
	catch(char *str)
	{
		cout<<"Exception :"<<str<<endl;
	}
return 0;
}
void queue ::ele_delete(void)
{
	head=(head+1)%max;
	size--;
	cout<<"After deleting size ="<<size<<"and head ="<<head<<endl;
}
int main(void)
{
	queue first;
	cout<<endl;
	while(1)
	{
		cout<<"Enter ur choice"<<endl;
		cout<<"1.add element"<<endl;
		cout<<"2.delete element"<<endl;
		cout<<"3.display queue"<<endl;
		cout<<"4.Exit......";
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1:
				first.ele_add();
				break;
			case 2:
				first.ele_delete();
				break;
			case 3:
				first.display();
				break;
			case 4:
				cout<<"U have choosed to exit from the program"<<endl;
				exit(0);
				break;
			default:
				cout<<"UR choice is wrong please check the choice"<<endl;
			
		}
	}
	
	
}
