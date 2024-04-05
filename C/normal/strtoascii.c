 #include<stdio.h>

#include<string.h> 
int main()
{
    char A[100];
    printf("Enter the string  ");
    scanf("%s",A);
    for (int i = 0; i < strlen(A); i++)
    {
        int g = (int) A[i];
        printf("%d ",g);
    }
}