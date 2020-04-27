#include <iostream>
using namespace std;

class Base
{
  protected:
  Base() {cout<<"Base constructor"<<endl;}
};

class derived : public Base
{
  public:
    derived() {cout<<"derived constructor"<<endl;}
};

int main()
{
  Base rb;
  derived d;
  return 0;
}
