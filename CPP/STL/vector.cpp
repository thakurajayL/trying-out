#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

int main()
{
  vector<int> vi;
  vector<char> vc;

  list<int> li;
  map<char,int> mci;

  cout<<"sizeof vi "<<sizeof(vi)<<endl;
  cout<<"sizeof vc "<<sizeof(vc)<<endl;
  cout<<"sizeof li "<<sizeof(li)<<endl;
  cout<<"sizeof mci "<<sizeof(mci)<<endl;
  return 0;
}
