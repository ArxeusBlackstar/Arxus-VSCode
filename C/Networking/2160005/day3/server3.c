#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct sockaddr_in serv_addr, cli_addr;
int sktfkt, acceptor, reader, writer, cliaddlen, binder, listener, num1, num2, oprnd;
unsigned short port = 5700;
const char *serip = "192.168.24.26";
char wbuff[128], rbuff[128];

int ascii(char aa[])
{
    int i = 0, j = 0, d = 0;
    for (i = 0; i < strlen(aa); i++)
    {
        d = (int)aa[i];
        d = d - 48;
        j = (j * 10) + d;
    }
}

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

    binder = bind(sktfkt, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (binder < 0)
    {
        printf("Bind Error");
        close(sktfkt);
        exit(69);
        return 1;
    }

    int yhivi = 1;   

    while (yhivi == 1)
    {
        int listener = listen(sktfkt, 1);
        if (listener < 0)
        {
            printf("Listen Error");
            close(sktfkt);
            exit(69);
            return 1;
        }

        printf("Listening for Clients....... Press 1 to continue, anything else to exit...");
        scanf("%d", &yhivi);
        if (yhivi == 0)
        {
            printf("Closing Server");
            close(sktfkt);
            exit(69);
        }

        cliaddlen = sizeof(cli_addr);

        acceptor = accept(sktfkt, (struct sockaddr *)&cli_addr, &cliaddlen);
        if (acceptor < 0)
        {
            printf("Accept Error");
            close(sktfkt);
            exit(69);
            return 1;
        }

        printf("Accepted connection from client");


        reader = read(acceptor, rbuff, sizeof(rbuff));
        if (reader < 0)
        {
            printf("Read Error");
            close(acceptor);
            close(sktfkt);
            exit(69);
            return 1;
        }
        
        else
        {
            printf("1st number :- %s", rbuff);
        }

        int num1 = 
        
        reader = read(acceptor, rbuff, sizeof(rbuff));
        if (reader < 0)
        {
            printf("Read Error");
            close(acceptor);
            close(sktfkt);
            exit(69);
            return 1;
        }
        
        else
        {
            printf("2nd number :- %s", rbuff);
        }

        reader = read(acceptor, rbuff, sizeof(rbuff));
        if (reader < 0)
        {
            printf("Read Error");
            close(acceptor);
            close(sktfkt);
            exit(69);
            return 1;
        }
        
        else
        {
            printf("operand :- %s", rbuff);
        }
    }
}