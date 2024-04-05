#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "ws2_32.lib")

struct sockaddr_in serv_addr;
SOCKET skfd;
int r, w;
unsigned short serv_port = 5600;
const char* serv_ip = "127.0.0.1";
char rbuff[128], sbuff[128];

int main() {
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
                printf("Failed to initialize Winsock.\n");
                return 1;
        }

        skfd = socket(AF_INET, SOCK_STREAM, 0);
        if (skfd == INVALID_SOCKET) {
                printf("\nCLIENT ERROR: Cannot create socket.\n");
                WSACleanup();
                return 1;
        }

        serv_addr.sin_family = AF_INET;                 // Address family
        serv_addr.sin_port = htons(serv_port);  // Port number
        serv_addr.sin_addr.s_addr = inet_addr(serv_ip); // IP address

        int connect_func = connect(skfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
        if (connect_func == SOCKET_ERROR) {
                printf("\nCLIENT ERROR: Cannot connect to the server.\n");
                closesocket(skfd);
                WSACleanup();
                return 1;
        }

        printf("\nCLIENT: Connected to the server.\n");
        while(1) {
                printf("Enter message (\"bye\" to exit) : ");
                gets(sbuff);

                w = send(skfd, sbuff, strlen(sbuff), 0);
                if(strcmp(sbuff,"bye")==0) {
                        closesocket(skfd);
                        WSACleanup();
                        return 1;
                }
                if (w < 0) {
                        printf("\nCLIENT ERROR: Cannot send message to the server.\n");
                        closesocket(skfd);
                        WSACleanup();
                        return 1;
                }
                else {
                        printf("\nCLIENT: Sent \"%s\" to %s\n", sbuff, serv_ip);
                }
                r = recv(skfd, rbuff, sizeof(rbuff), 0);
                if(strcmp(rbuff,"bye")==0) {
                        closesocket(skfd);
                        WSACleanup();
                        return 1;
                }
                if (r < 0) {
                        printf("\nCLIENT ERROR: Cannot receive message from the server.\n");
                } else {
                        rbuff[r] = '\0';
                        printf("\nCLIENT: Server Message: %s\n", rbuff);
                }
        }
        closesocket(skfd);
        WSACleanup();
        return 0;
}

// gcc serverchat.c -o serverchat -lws2_32

