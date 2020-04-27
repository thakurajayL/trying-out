#include<iostream>
#include<string>

using namespace std;
class vector
{
	//by default members are private 
	public:
		double x,y;
		vector() {;}
		vector(double, double);
		vector operator*(double);
		vector operator+(vector);
		void display(std::string);
};

vector::vector(double a, double b)
{
	x = a;
	y = b;
}

void vector::display(std::string name)
{
	std::cout<<"Name "<<name<<" Vector =("<<x<<","<<y<<")"<<std::endl;
	return;
}

vector vector::operator +(vector b)
{
	vector r;
	r.x=x + b.x;
	r.y=y + b.y;
	return r;	
}

vector vector::operator*(double a)
{
	vector r;
	r.x=a*x;
	r.y=a*y;
	return r;	
}

int main(void)
{
	vector k(2,3);
	vector m;

	k.display("k");
	m=k*1.2;
	m.display("m after *1.2");
	return 0;
}
