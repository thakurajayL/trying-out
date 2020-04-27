#include <iostream>
using namespace std;

struct Test
{
  char u;
  int  x;
}__attribute__((__packed__));

class base
{
  char u;
  int  x;
  public:
    void set_data(int a, int b);
}__attribute__((__packed__));

int main()
{
  struct Test t;
  class  base b;
  cout<<"t = "<<sizeof(t)<<endl;
  cout<<"t = "<<sizeof(b)<<endl;
  return 0;
}
