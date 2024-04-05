#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct sockaddr_in serv_addr, cli_addr;
int sockfd, connfd;
int r, w, cliaddlen;
unsigned short serpor = 5700;
const char *serip = "192.168.24.26";
char sbuff[128], rbuff[128];
static char date[2000];

char *timmeh()
{
    long long int timsec, timmin, timewhour, timday, timeyawr;
    int secnow, minnow, hrnow, dynow, yrnow;
    char month[12][12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int monthay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    timsec = time(NULL);

    timmin = timsec / 60;

    timewhour = timsec / (60 * 60);

    timday = timewhour / 24;

    long long a = ((timday * 3) / (4 * 365));

    long long b = ((timday * 1) / (4 * 366));

    timeyawr = a + b;

    yrnow = timeyawr + 1970;

    dynow = timday - (((timeyawr * 3 * 365) / 4) + ((timeyawr * 366) / 4));
    dynow--;

    hrnow = timewhour - (timday * 24);

    minnow = timmin - (timewhour * 60);

    secnow = timsec - (timmin * 60);

    int day = dynow, num = 0;
    if (yrnow % 4 == 0)
    {
        monthay[1] = 29;
    }
    while (day > monthay[num])
    {
        day = day - monthay[num];
        num++;
    }
    day++;

    sprintf(date, "Its the year -> %d / month -> %s / days -> %d / date -> %d / hours -> %d / minutes -> %d / seconds -> %d /", yrnow, month[num], dynow, day, hrnow, minnow, secnow);

    return date;
}


int main()
{
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("SERVER ERROR: Cannot create socket");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(serpor);
    serv_addr.sin_addr.s_addr = inet_addr(serip);

    int bind_func = bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (bind_func == -1)
    {

        printf("SERVER ERROR: Cannot bind");
        close(sockfd);
        return 1;
    }

    while (1)
    {

        int listen_func = listen(sockfd, 1);
        if (listen_func == -1)
        {

            printf("SERVER ERROR: Cannot listen");
            close(sockfd);
            return 1;
        }

        cliaddlen = sizeof(cli_addr);
        printf("SERVER: Listening for clients... Press Ctrl + C to stop the echo server.\n");
        connfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cliaddlen);

        if (connfd == -1)
        {
            printf("SERVER ERROR: Cannot accept client connection");
            close(sockfd);
            return 1;
        }

        printf("SERVER: Connection from client %s accepted.\n", inet_ntoa(cli_addr.sin_addr));

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

            w = send(connfd, date, r, 0);
            if (w == -1)
            {
                printf("SERVER ERROR: Cannot send message to the client");
            }
            else
            {
                printf("SERVER: Sent \"%s\" to %s.\n", rbuff, inet_ntoa(cli_addr.sin_addr));
            }
            if (strcmp(rbuff, "bye") == 0)
            {
                break;
            }
        }
        close(connfd);
    }
    close(sockfd);
    return 0;
}