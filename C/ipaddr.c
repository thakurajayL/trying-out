#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    char *ipPool="192.168.0.0";
    char *ipMask="255.255.0.0";

    struct in_addr pool, mask;

    inet_aton(ipPool, &pool);
    inet_aton(ipMask, &mask);

    printf("Address = %s Mask = %s ", inet_ntoa(pool), inet_ntoa(mask));
    return 0;
}
