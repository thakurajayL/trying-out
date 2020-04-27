#include <iostream>
using namespace std;
// overloading of generic functions ...
//
template <class type1, class type2> void myfunc(type1 x, type2 y)
{
  cout <<"Type1 variable = "<<x<<" type2 variable =  "<<y<<endl;
}

template <class type1, class type2, class type3> void myfunc(type1 x, type2 y, type3 z)
{
  cout <<"Type1 variable = "<<x<<" type2 variable =  "<<y<<" type 3 = "<<z<<endl;
}


int main()
{
  // using generic function for different args example 1.
  myfunc(10,"I love C++");
  // using generic function for different args example 2.
  myfunc('a', 'b');

  myfunc(1000, 2000, 3000);

  return 0;
}
