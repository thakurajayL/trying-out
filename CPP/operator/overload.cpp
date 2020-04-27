#include <iostream>
using namespace std;

class Test
{
  int a;
  int b;
  public:
    void print_data(void) {cout<<"a = "<<a<<" b = "<<b<<endl;}
    void operator()(int x, int y){cout<<"Inside () overloaded function "<<x<<endl;}
    Test(int x, int y) { cout<<"inside constructor"<<endl;a = x; b = y; }
};

int main()
{
  Test obj(1,2);
  obj(5,6);
  return 0;
}
