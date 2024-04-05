#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h> // Corrected header name
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h> // Added header for exit()

struct sockaddr_in serv_addr, cli_addr;
int sockfd, connfd, r, w, val, cliaddlen;
unsigned short serv_port = 12345; // Set your desired port number
char serv_ip[] = "127.0.0.1";     // Set your server's IP address
char buff[128];

int main()
{
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(serv_port);
    inet_aton(serv_ip, &serv_addr.sin_addr); // Corrected inet_aton function call
    printf("\nTCP ECHO SERVER.\n");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\nSERVER ERROR : Cannot create socket.\n");
        exit(1);
    }

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nSERVER ERROR : Cannot bind.\n");
        close(sockfd);
        exit(1);
    }

    if (listen(sockfd, 5) < 0)
    {
        printf("\nSERVER ERROR : Cannot listen.\n");
        close(sockfd);
        exit(1);
    }

    cliaddlen = sizeof(cli_addr);

    while (1) // Added loop condition
    {
        printf("\nSERVER : Listening for clients... press ctrl + c to stop echo server :\n");
        if ((connfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cliaddlen)) < 0)
        {
            printf("\nSERVER ERROR : Cannot accept client connection.\n");
            close(sockfd);
            exit(1);
        }
        printf("\nSERVER : Connection from client %s accepted.\n", inet_ntoa(cli_addr.sin_addr));
        if ((r = read(connfd, buff, 128)) < 0)
            printf("\nSERVER ERROR : Cannot receive message from the client.\n");
        else
        {
            buff[r] = '\0';
            if ((w = write(connfd, buff, r)) < 0) // Changed to write only the received bytes
                printf("\nSERVER ERROR : Cannot send message to the client.\n");
            else
                printf("\nSERVER : Echoed back %s to %s.\n", buff, inet_ntoa(cli_addr.sin_addr));
        }
        close(connfd); // Close the connection after echoing back the message
    }

    close(sockfd);
    return 0;
}