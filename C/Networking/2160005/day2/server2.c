#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct sockaddr_in seradr, cliadr;
int sktfkt, connfd;
int r, w, cliaddlen;
unsigned short port = 5700;
const char *serip = "192.168.24.26";
char sbuff[128], rbuff[128];

int main()
{
    sktfkt = socket(AF_INET, SOCK_STREAM, 0);
    if (sktfkt == -1)
    {
        printf("SERVER ERROR: Cannot create socket");
        return 1;
    }

    seradr.sin_family = AF_INET;
    seradr.sin_port = htons(port);
    seradr.sin_addr.s_addr = inet_addr(serip);

    int bind_func = bind(sktfkt, (struct sockaddr *)&seradr, sizeof(seradr));
    if (bind_func == -1)
    {
        printf("SERVER ERROR: Cannot bind");
        close(sktfkt);
        return 1;
    }

    while (1)
    {
        int listen_func = listen(sktfkt, 1);
        if (listen_func == -1)
        {
            printf("SERVER ERROR: Cannot listen");
            close(sktfkt);
            return 1;
        }

        cliaddlen = sizeof(cliadr);

        printf("SERVER: Listening for clients... Press Ctrl + C to stop the echo server.\n");
        connfd = accept(sktfkt, (struct sockaddr *)&cliadr, &cliaddlen);
        if (connfd == -1)
        {
            printf("SERVER ERROR: Cannot accept client connection");
            close(sktfkt);
            return 1;
        }
        printf("SERVER: Connection from client %s accepted.\n", inet_ntoa(cliadr.sin_addr));

        while (1)
        {
            r = recv(connfd, sbuff, sizeof(sbuff), 0);
            if (r == -1)
            {
                printf("SERVER ERROR: Cannot receive message from the client");
            }
            else
            {
                sbuff[r] = '\0';
                printf("SERVER: Client Message: %s\n", sbuff);
            }
            if (strcmp(sbuff, "bye") == 0)
            {
                break;
            }

            printf("Enter message (\"bye\" to exit) : ");
            fgets(rbuff, sizeof(rbuff), stdin);
            rbuff[strcspn(rbuff, "\n")] = '\0';

            w = send(connfd, rbuff, r, 0);
            if (w == -1)
            {
                printf("SERVER ERROR: Cannot send message to the client");
            }
            else
            {
                printf("SERVER: Sent \"%s\" to %s.\n", rbuff, inet_ntoa(cliadr.sin_addr));
            }
            if (strcmp(rbuff, "bye") == 0)
            {
                break;
            }
        }
        close(connfd);
    }
    close(sktfkt);
    return 0;
}