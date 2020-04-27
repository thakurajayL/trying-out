#include <iostream>
using namespace std;


template <class T1> void exchange(T1 &x,T1 &y)
{
  T1 temp;
  temp = x;
  x = y;
  y = temp;
}

int main()
{
  /* using exchange function for integer swap */
  int i = 10, j = 20;
  cout<<"before swap i = " << i << " j = "<<j<<endl;
  exchange(i,j);
  cout<<"After swap i = " << i << " j = "<<j<<endl;

  /* using exchange function for character swap */
  char a = 'a', b = 'b';
  cout<<"before swap a = " << a << " b = "<<b<<endl;
  exchange(a,b);
  cout<<"After swap a = " << a << " b = "<<b<<endl;



  return 0;
}

#if 0
void exchange(Name &n1, Name &n2)
{
  Name temp;
  temp = n1;
  n1 = n2;
  n2 = temp;
  return;
}

void exchange(Roll &n1, Roll &n2)
{
  Roll temp;
  temp = n1;
  n1 = n2;
  n2 = temp;
  return;
}
#endif
