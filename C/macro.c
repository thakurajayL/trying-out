#include<stdio.h>

#define quoted(TEXT) #TEXT
int main(void)
{
	short pant;
	printf("%s",quoted(3));
	return 0;
}
