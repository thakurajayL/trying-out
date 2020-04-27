#include <iostream>
using namespace std;

class gdb {
  protected:
        int k;
  private:
        int i;
  public:
        int j;
        gdb(){i=10;j=20;k=30; t = 40;}
        void print_class() { cout<<" i = "<<i<<" j = "<<j<<" k = "<<k<<endl;}
  protected:
        int t;

};

template <class type1, class type2> void myfunc(type1 x, type2 y)
{
  cout <<"Type1 variable = "<<x<<" type2 variable =  "<<y<<endl;
}

int main()
{
  // using generic function for different args example 1.
  myfunc(10,"I love C++");
  // using generic function for different args example 2.
  myfunc('a', 'b');

  myfunc(1000, 20);

  gdb temp;
  temp.print_class();

  return 0;
}
