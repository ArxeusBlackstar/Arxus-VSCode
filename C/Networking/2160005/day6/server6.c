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
unsigned short port = 6969;
const char *serip = "127.0.0.1";

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

    char wbuff[65536], rbuff[65536], line[65536], loaf[1024] = "ls ", wbuff1[65536], rbuff1[65536], line1[65536], loaf1[1024] = "cat ";

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
    if (strcmp(rbuff, "killit") == 0)
    {
        exit(1);
    }

    strcat(loaf, rbuff);
    strcat(loaf, "*> muthput");
    printf("\n");

    int p = system(loaf);
    printf("%d\n", p);
    if (p == 0)
    {
        printf("\n Server says :- Valid Shit \n");
    }
    else
    {
        printf("\n Server says : File not present \n");
    }

    FILE *fp;
    fp = fopen("muthput", "r");

    if (fp == NULL)
    {
        printf("Cannot open file");
        exit(1);
    }

    int i = 0;

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        strcat(wbuff, line);
        i++;
    }

    printf("Number of files %d", i);

    char randomshit[12];
    sprintf(randomshit, "%d", i);

    strcat(wbuff, "\n Number of files: ");
    strcat(wbuff, randomshit);

    fclose(fp);
    system("rm muthput");

    writer = write(acceptor, wbuff, sizeof(wbuff));
    if (writer < 0)
    {
        printf("\n Write Error \n");
    }
    else
    {
        printf("\n Sent \n");
    }

    // hvjvvuvugvjhvuyygfuyvgjuhbiyvuyfvutgfvuvuyvuyygugfuvufvufvutuvu

    reader = read(acceptor, rbuff1, sizeof(rbuff1));
    if (reader < 0)
    {
        printf("\n Read Error \n");
    }
    else
    {
        rbuff1[reader] = '\0';
        printf("\n Server: Client says : %s \n", rbuff1);
    }
    if (strcmp(rbuff1, "killit") == 0)
    {
        exit(1);
    }

    strcat(loaf1, rbuff1);
    strcat(loaf1, "> muthput");
    printf("\n");

    p = system(loaf1);
    printf("%d\n", p);
    if (p == 0)
    {
        printf("\n Server says :- Valid Shit \n");
    }
    else
    {
        printf("\n Server says : File not present \n");
    }

    FILE *fp1;
    fp1 = fopen("muthput", "r");

    if (fp1 == NULL)
    {
        printf("Cannot open file");
        exit(1);
    }

    while (fgets(line1, sizeof(line1), fp1) != NULL)
    {
        strcat(wbuff1, line1);
    }

    fclose(fp1);

    writer = write(acceptor, wbuff1, sizeof(wbuff1));
    if (writer < 0)
    {
        printf("\n Write Error \n");
    }
    else
    {
        printf("\n Sent \n");
    }

    printf("%s", wbuff1);

    close(acceptor);

    close(sktfkt);
    return 0;
}
