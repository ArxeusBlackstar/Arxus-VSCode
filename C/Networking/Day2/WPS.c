#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "ws2_32.lib")

struct sockaddr_in serv_addr, cli_addr;
SOCKET listenfd, connfd;
int r, w, cli_addr_len;
unsigned short serv_port = 5600;
const char* serv_ip = "127.0.0.1"; // Loopback address for testing
char sbuff[128], rbuff[128];

int main() {
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
                printf("Failed to initialize Winsock.\n");
                return 1;
        }

        listenfd = socket(AF_INET, SOCK_STREAM, 0);
        if (listenfd == INVALID_SOCKET) {
                printf("SERVER ERROR: Cannot create socket.\n");
                WSACleanup();
                return 1;
        }

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(serv_port);
        serv_addr.sin_addr.s_addr = inet_addr(serv_ip);

        int bind_func = bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
        if (bind_func == SOCKET_ERROR) {
                printf("SERVER ERROR: Cannot bind.\n");
                closesocket(listenfd);
                WSACleanup();
                return 1;
        }
        while (1) {
                int listen_func = listen(listenfd, 1);
                if (listen_func == SOCKET_ERROR) {
                        printf("SERVER ERROR: Cannot listen.\n");
                        closesocket(listenfd);
                        WSACleanup();
                        return 1;
                }

                cli_addr_len = sizeof(cli_addr);

                printf("SERVER: Listening for clients... Press Ctrl + C to stop the echo server.\n");
                connfd = accept(listenfd, (struct sockaddr*)&cli_addr, &cli_addr_len);
                if (connfd == INVALID_SOCKET) {
                        printf("SERVER ERROR: Cannot accept client connection.\n");
                        closesocket(listenfd);
                        WSACleanup();
                        return 1;
                }
                printf("SERVER: Connection from client %s accepted.\n", inet_ntoa(cli_addr.sin_addr));
                for (;;) {
                        r = recv(connfd, sbuff, sizeof(sbuff), 0);
                        if (r == SOCKET_ERROR) {
                                printf("SERVER ERROR: Cannot receive message from the client.\n");
                        } else {
                                sbuff[r] = '\0';
                                printf("SERVER: Client Message: %s\n",sbuff);
                        }
                        if (strcmp(sbuff,"bye")==0) {
                                break;
                        }

                        printf("Enter message (\"bye\" to exit) : ");
                        gets(rbuff);

                        w = send(connfd, rbuff, r, 0);
                        if (w == SOCKET_ERROR) {
                                printf("SERVER ERROR: Cannot send message to the client.\n");
                        } else {
                                printf("SERVER: Sent \"%s\" to %s.\n", rbuff, inet_ntoa(cli_addr.sin_addr));
                        }
                        if (strcmp(rbuff,"bye")==0) {
                                break;
                        }
                }
        }
        closesocket(connfd);
        closesocket(listenfd);
        WSACleanup();
        return 0;
}