#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct sockaddr_in serv_addr, cli_addr;
int sktfkt, acceptor, reader, writer, cliaddlen, connector, listener, num1, num2, oprnd;
unsigned short port = 5700;
const char *serip = "192.168.24.26";
char wbuff[128], rbuff[128];

int main()
{
    sktfkt = socket(AF_INET, SOCK_STREAM, 0);
    if (sktfkt < 0)
    {
        printf("Socket Error");
        exit(69);
        return 1;
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(serip);
    
    connector = connect(sktfkt, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (connector < 0)
    {
        printf("Connection Error");
        close(sktfkt);
        exit(69);
        return 1;
    }
    printf("Connected to server");

    while (1)
    {
        printf("Enter the 1st Operand");
        scanf("%[^\n]s", &wbuff);

        writer = write(sktfkt, wbuff, strlen(wbuff));

        if (writer < 0)
        {
            printf("Write Error");
            close(sktfkt);
            exit(69);
            return 1;
        }





    }
}