#include <iostream>
using namespace std;

template <class AType, int size> class atype {
  AType a[size];
  public:
  atype() {
    int i;
    for(i=0;i<size;i++)
      a[i] = i;
  }
  AType &operator[](int index);
};

template <class AType, int size> AType &atype<AType, size>::operator[] (int index)
{
  cout<<"inside () overloaded function "<<index;
  return a[index];
}


int main()
{
  atype<int, 10> intob;
  int i;

  cout<< "printing setting integer array"<<endl;
  for(i=0;i<10;i++) {
    cout<<" intob["<<i<<"] = "<<intob[i]<<endl;
  }
  return 0;
}
