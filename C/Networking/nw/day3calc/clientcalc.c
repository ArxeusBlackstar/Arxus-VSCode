#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct sockaddr_in serv_addr;
int  r, w1, w2, w3, c_sock_desc;
unsigned short serv_port = 5800 ; 
char serv_ip[] = "192.168.24.17";
char op1[128], op2[128], operand[128], s_result[128];

int main()
{
	c_sock_desc = socket(AF_INET, SOCK_STREAM, 0);
	if(c_sock_desc < 0)
	{
		printf("\nCLIENT ERROR : Cannot create socket.\n");
		exit(1);
	}
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(serv_port);
	inet_aton(serv_ip, (&serv_addr.sin_addr));
	
	int connect_func= connect(c_sock_desc, (struct sockaddr*)&serv_addr, sizeof(serv_addr));	
	if(connect_func < 0)
	{
		printf("\nCLIENT ERROR : Cannot connect to the server.\n");
		close(c_sock_desc);
		exit(1);
	}
	printf("\nCLIENT : Connected to the server.\n");
	printf("Operator1 : ");
	gets(op1);
	printf("Operator2 : ");
	gets(op2);
	printf("Operand : ");
	gets(operand);
		
	w1 = write(c_sock_desc, op1, 128);
	w2 = write(c_sock_desc, op2, 128);
	w3 = write(c_sock_desc, operand, 128);
	printf("OP : %s", operand);
	if((w1 < 0) || (w2 < 0) || (w3 < 0))
	{
		printf("\nCLIENT ERROR : Cannot send message to the server.\n");
		close(c_sock_desc);
		exit(1);
	}
	op1[w1]='\0';
	op1[w2]='\0';
	operand[w3]='\0';
	
	r = read(c_sock_desc, s_result,128);
	if(r < 0)
		printf("\nCLIENT ERROR : Cannot receive result from the server.\n");
	else
	{
		s_result[r] = '\0';
		printf("\nCLIENT : SERVER MESSAGE: Result : %s\n", s_result);
	}
	close(c_sock_desc);
	exit(1);
}
