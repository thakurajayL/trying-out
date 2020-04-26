/*exception handling*/
#include <iostream>
#include<string.h>
class exc{ 
	public:
		char err[20];
   	exc(const char *str)
	{	
		strcpy(err,str);
	}
};

int main () 
{
  char myarray[10];
  try
  {
    for (int n=0; n<=10; n++)
    {
      if (n>9) { 
	      throw exc("Array Bound Overrun");
      }
      myarray[n]='z';
    }
  }
  catch (exc &p)
  {
	  std::cout << "Exception: " <<p.err<< std::endl;
  }
  return 0;
}
