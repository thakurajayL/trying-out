#include <iostream>
using namespace std;

#define SIZE 10

class Test {
  public:
    int a[SIZE];
    Test() {a[0] = 0; a[1] = 1; a[2] = 2;}
    int operator[](int k) {
      cout<<"Index k = "<<k<<endl;
      return a[k];
    }
};

int main()
{
  Test obj;

  cout<<"Hi...calling obj[1] "<<obj[1]<<endl;
  return 0;
}
