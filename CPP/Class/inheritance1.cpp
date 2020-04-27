#include <iostream>
using namespace std;
class Base1
{
  int b;
public:
  void set_b(int i) { b = i; }
  void show_b1() { cout<<"Base1 b = "<<b<<endl;}

};
class Base2
{
  int b;
public:
  void set_b(int i) { b = i; }
  void show_b2() { cout<<"Base2 b = "<<b<<endl;}

};
class Derive1 : public Base1, public Base2
{
  int d;
public:
  Derive1(int i) {d = i;b=i*2;}
  void show_b(void) { cout<<"derive class D = "<<d<<"b= "<<b<<endl;}
};
int main()
{
  Derive1 d_obj1=55;
  d_obj3.show_b();

  cout<<"\n";
  return 0;
}
