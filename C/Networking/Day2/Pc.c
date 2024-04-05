#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h> 

struct sockaddr_in serv_addr;
int sktfkt, r, w;
unsigned short serpor = 5600;
const char *serip = "192.168.56.1";
char rbuff[128], sbuff[128];

int main()
{
    sktfkt = socket(AF_INET, SOCK_STREAM, 0);
    if (sktfkt == -1)
    {
        perror("\nCLIENT ERROR: Cannot create socket");
        return 1;
    }

    serv_addr.sin_family = AF_INET;                 
    serv_addr.sin_port = htons(serpor);          
    serv_addr.sin_addr.s_addr = inet_addr(serip); 

    if (connect(sktfkt, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        perror("\nCLIENT ERROR: Cannot connect to the server");
        close(sktfkt);
        return 1;
    }

    printf("\nCLIENT: Connected to the server.\n");
    while (1)
    {
        printf("Enter message (\"bye\" to exit) : ");
        fgets(sbuff, sizeof(sbuff), stdin);
        sbuff[strcspn(sbuff, "\n")] = '\0'; 

        w = send(sktfkt, sbuff, strlen(sbuff), 0);
        if (strcmp(sbuff, "bye") == 0)
        {
            close(sktfkt);
            return 0;
        }
        if (w < 0)
        {
            perror("\nCLIENT ERROR: Cannot send message to the server");
            close(sktfkt);
            return 1;
        }
        else
        {
            printf("\nCLIENT: Sent \"%s\" to %s\n", sbuff, serip);
        }

        r = recv(sktfkt, rbuff, sizeof(rbuff) - 1, 0);
        if (r == 0)
        {
            printf("\nCLIENT: Server closed the connection.\n");
            break;
        }
        if (r < 0)
        {
            perror("\nCLIENT ERROR: Cannot receive message from the server");
        }
        else
        {
            rbuff[r] = '\0';
            printf("\nCLIENT: Server Message: %s\n", rbuff);
        }
    }
    close(sktfkt);
    return 0;
}