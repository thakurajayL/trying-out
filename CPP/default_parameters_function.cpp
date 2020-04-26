#include<iostream>
using namespace std;
void printline(char ch='*', int length=40);

void printline(char ch, int length)
{
	int i;
	for(i=0;i<length;i++)
		cout<<ch;
	cout<<endl;
}

int main (void)
{
	printline('#',10);
	printline('%');
	printline();

}
