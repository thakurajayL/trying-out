#include <iostream>
using namespace std;
// overloading of generic functions ...
//
template <class type1, class type2> void myfunc(type1 x, type2 y, int z=10)
{
  cout <<"Type1 variable = "<<x<<" type2 variable =  "<<y<<" z = "<<z<<endl;
}


int main()
{
  // using generic function for different args example 1.
  myfunc(10, "I love C++");
  myfunc(10, "I love C++", 30);

  return 0;
}

/*
 * 1. template functions can have standard datatype
 * 2. template functions parameters can have default value
 * 3. order of template class & in the function argument does not matter, but
 * while making a function call parameters should be passed correctly
 */
