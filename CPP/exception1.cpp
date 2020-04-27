#include <iostream>
using namespace std;

int main()
{
  try {
    cout<<"Test exception"<<endl;
    throw 1;
  }
  catch(int i)
  {
    cout<<"1 Exception received "<<i;
  }
  catch(int k)
  {
    cout<<"2 Exception received "<<k;
  }
  cout<<endl;
  return 0;
}
