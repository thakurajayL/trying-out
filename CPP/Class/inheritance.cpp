#include <iostream>
using namespace std;

class Base1
{
  int b;
  static int b_static1;
public:
  void set_b(int i) { b = i; }
  static void show_bstatic1(void) {b_static1++; cout<<"static1 = "<<b_static1<<endl;}
  void show_b1() { cout<<"Base1 b = "<<b<<endl;}

};

class Base2
{
  int b;
  static int b_static2;
public:
  void set_b(int i) { b = i; }
  static void show_bstatic2(void) {b_static2++; cout<<"static = "<<b_static2<<endl;}
  void show_b2() { cout<<"Base2 b = "<<b<<endl;}

};


class Derive1 : public Base1, public Base2
{
  int d;
public:
  Derive1(int i) {d = i;}
  void show_d(void) { cout<<"derive class D = "<<d<<endl;}
};

class Derive2 : public Base1
{
  int d;
public:
  Derive2(int i) {d = i;}
  void show_d(void) { cout<<"derive1 class D = "<<d<<endl;}
};


int Base1::b_static1=10;
int main()
{
  Derive1 d_obj1=55;
  Derive2 d_obj2=155;
  d_obj1.show_d();
  Base1::show_bstatic1();
  Base1::show_bstatic1();
  d_obj1.show_bstatic1();
  d_obj2.show_d();
  d_obj2.show_bstatic1();


  Derive1 d_obj3=55;
  d_obj3.show_b1();

  cout<<"\n";
  return 0;
}
