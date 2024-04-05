#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
	int p;

	char string1[100] = "date";
	system(string1);	

	char string2[100] = "ls";
	p = system(string2);
	printf("%d\n", p);

	char string3[100] = "ls";
	p = system(string3);
	printf("%d\n", p);

	char string4[100] = "xyz";
	p = system(string4);
	printf("%d\n", p);

	char string5[100] = "yuio";
	p = system(string5);
	printf("%d\n", p);

	char string6[100] = "yhivi";
	p = system(string6);
	printf("%d\n", p);

	char string7[100] = "kleio";
	p = system(string7);
	printf("%d\n", p);

	char loaf[10] = "ls ";
    strcat(loaf, "p");
    strcat(loaf, "*> muthput");            
    p = system(loaf);
	printf("%d\n", p);

	fgets()




}
