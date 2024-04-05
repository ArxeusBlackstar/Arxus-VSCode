#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h> // Corrected the header name
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h> // Added the missing header for exit()

struct sockaddr_in serv_addr;
int r, w, sockfd;
unsigned short serport = 12345; // Set your desired port number
char serip[] = "192.168.56.1";
char rbuff[128];
char sbuff[] = "Hello Server"; // Removed unnecessary size in sbuff

int main()
{
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; // Corrected the typo: 'serv addr' to 'serv_addr'
    serv_addr.sin_port = htons(serport);
    inet_aton(serip, &serv_addr.sin_addr);
    printf("\nTCP ECHO CLIENT.\n");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\nCLIENT ERROR : Cannot create socket.\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nCLIENT ERROR : Cannot connect to the server.\n");
        close(sockfd);
        exit(1);
    }

    printf("\nCLIENT : Connected to the server.\n");
    if ((w = write(sockfd, sbuff, strlen(sbuff))) < 0) // Used sockfd and strlen(sbuff)
    {
        printf("\nCLIENT ERROR : Cannot send message to the server.\n");
        close(sockfd);
        exit(1);
    }

    printf("\nCLIENT : Message sent to echo server.\n");
    if ((r = read(sockfd, rbuff, sizeof(rbuff) - 1)) < 0) // Used sockfd and sizeof(rbuff)
        printf("\nCLIENT ERROR : Cannot receive message from the server.\n");
    else
    {
        rbuff[r] = '\0';
        printf("\nCLIENT : Message received from echo server: %s\n", rbuff);
    }
    close(sockfd);
    return 0; // Changed exit(1) to return 0 to indicate successful execution
}