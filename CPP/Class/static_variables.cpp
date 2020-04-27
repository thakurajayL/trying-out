#include<iostream>

using namespace std;

class special
{
	static int count; // static variable
	public:
		void getcount(void)
		{
			cout<< "COUNT IS :"<<count<<endl;
		}

		void add_count (void)
		{
			count++;
		}
};

int special :: count; // static variable

int main (void)
{
	special A,B;
	A.getcount();
	A.add_count();
	A.getcount();
	B.add_count();
	B.getcount();
	return 0;
}
