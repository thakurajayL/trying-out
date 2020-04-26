#include<iostream>
using namespace std;
class first
{
	private:
		int age;
		char name[10];
	public:
		void getdata(void);
		void display(void);
};

void first::getdata (void)
{
	cout<<"Enter ur age and name "<<endl;
	cin>>age>>name;
}

void first :: display (void)
{
	cout<<"Your name is "<<name<<" and your age is "<< age<<endl;
}

int main(void)
{
	first  test;
	test.getdata();
	test.display();
	return 0;
}
