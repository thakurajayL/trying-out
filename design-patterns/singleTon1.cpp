#include <iostream>
using namespace std;
class Singleton
{
public:
        static Singleton& getInstance();

private:
        Singleton(){}
};


Singleton& Singleton::getInstance()
{
  static Singleton instance;
  return instance;
}
int main()
{
        Singleton &s1 = Singleton::getInstance();
        Singleton &s2 = Singleton::getInstance();
        return 0;
}
