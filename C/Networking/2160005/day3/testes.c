#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char t = '1';
    char tt[] = "aaaa";
    int sock = (int)t; 
    printf("%d\n", sock);
    printf("%s\n", tt);
}