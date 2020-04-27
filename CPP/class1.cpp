#include <iostream>
#include <string.h>

using namespace std;

class Fruit
{
  char name[100];
  bool color; // black or white
  bool taste; // sweet or sour

public:
  void set_taste(bool t);
  void set_color(bool c);
  void set_name(const char *name);
  void display_fruit(void);
};

void Fruit :: set_taste(bool t)
{
  taste = t;
}

void Fruit :: set_color(bool c)
{
  color = c;
}

void Fruit :: set_name(const char *n)
{
  strcpy(name, n);
}

void Fruit :: display_fruit(void)
{
  cout << "Fruit name = " << name;
  cout << "Fruit color = " << color;
  cout << "Fruit taste = " << taste;
}
int main()
{
  class Fruit banana;
  banana.set_taste(1);
  banana.set_color(1);
  banana.set_name("banana");
  banana.display_fruit();
  return 0;
}
