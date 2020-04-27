#include <iostream>
#include <cxxabi.h>

using namespace std;
class Base
{
};
class Derived : public Base {
};
int main()
{
  Derived d;
  Base    b;
  int status;
  cout << "typeid(d) "<<typeid(d).name()<<endl;
  cout << "typeid(b) "<<typeid(b).name()<<endl;
  cout<<"Demangled name = "<<abi::__cxa_demangle(typeid(d).name(), 0, 0, &status);
  cout<<endl;
  return 0;
}
