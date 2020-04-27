#include<iostream>
using namespace std;
class fun
{
	static int count;
	public:
		static void get_count(void)
		{
			cout<<"COUNT is "<<count<<endl;
		}
		void add_count(void)
		{
			count++;
		}
	
};
int fun :: count; // static variable declaration;
int main (void)
{
	fun A,B;
	A.add_count();
	fun ::get_count();
	B.add_count();
	fun::get_count();
	return 0;
}
