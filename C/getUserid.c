#include <unistd.h>
#include <sys/types.h>
#include "stdio.h"

int main()
{
	uid_t id = getuid();
	printf("\n get user id = %u\n",id);
	if(id != 0) {
		printf("\n You need to be ROOT user to run this program");
	}
	return 0;
}
