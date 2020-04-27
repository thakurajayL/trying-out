#include <iostream>
using namespace std;

template <class stacktype> class stack {
  stacktype stck[10];
  int tos;

  public:
    stack() {tos = 0; cout <<"constuctor is called "<<endl;}
    void push(stacktype obj);
    stacktype pop(void);

};

template <class stacktype> void stack<stacktype>::push(stacktype obj)
{
  if(tos == 10) {
    cout <<"stack1 is full"<<endl;
    return;
  }
  cout<<"pushing "<<obj<<endl;
  stck[tos] = obj;
  tos++;
}


template <class stacktype> stacktype stack<stacktype>::pop(void)
{
  if(tos == 0) {
    cout << "stack1 is empty "<<endl;
    return 0;
  }
  tos--;
  cout<<"popped "<<stck[tos]<<endl;
  return stck[tos];
}


int main()
{
  stack<int> s1;
  s1.push(10);
  s1.push(20);
  s1.push(30);
  s1.push(40);
  s1.pop();
  s1.pop();
  s1.pop();
  s1.pop();
  s1.pop();

  stack<char> s2;
  s2.push('a');
  s2.push('b');
  s2.push('c');
  s2.push('d');
  s2.pop();
  s2.pop();
  s2.pop();
  s2.pop();
  s2.pop();
  return 0;
}
