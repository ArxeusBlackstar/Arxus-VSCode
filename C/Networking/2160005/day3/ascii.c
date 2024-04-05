#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char aa[128] = "69789";

int main()
{
    int i = 0, j = 0, d = 0;
    for (i = 0; i < strlen(aa); i++)
    {
        d = (int)aa[i];
        d = d - 48;
        j = (j * 10) + d;
    }
    printf("%d\n", j);
}