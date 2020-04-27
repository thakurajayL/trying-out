#include <iostream>
using namespace std;
class myClass {
private:
       int data;
       int *ptr;
public:
     myClass() {
        data = 0;
        ptr  = NULL;
        }
     myClass(int x) { data = x;ptr=new int;}
     int getdata(void) { return data;}
     // myClass(const myClass &t) {data = t.data;}
     //myClass(const myClass &t, int add = 0);
     myClass(const myClass &t, int add = 0) {
     data = t.data + add;
     }
};

int main()
{
  myClass t;
  cout<<"Data = "<<t.getdata()<<"\n";

  myClass p(1);
  cout<<"p Data = "<<p.getdata()<<"\n";

  myClass p1 = 2;
  cout<<"p1 Data = "<<p1.getdata()<<"\n";

  myClass p2 = myClass(3);
  cout<<"p2 Data = "<<p2.getdata()<<"\n";

  myClass t1 = p2;
  cout<<"t1 Data = "<<t1.getdata()<<"\n";

  myClass t2(p1, 20);
  cout<<"t2 Data = "<<t2.getdata()<<"\n";

  myClass t3(p1);
  cout<<"t3 Data = "<<t3.getdata()<<"\n";


  return 0;
}
