#include<stdio.h>

#include<string.h>
int main()
{
    int l=0,num=0,blanks=0,tabs=0,newl=0;
    char str[1000];
    
    printf("Enter the string\n");
    scanf("%[^\n]s",&str);
    l = strlen(str);

    for (int i = 0; i < l; i++)
    {
        char ch=str[i];
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
        }
        else
        {
            if (ch == ' ')
            {
                blanks++;
            }
            else if (ch == '\t')
            {
                tabs++;
                ch = 't';
                printf("/");
            }
            else if (ch == '.')
            {
                newl++;
                ch = 'n';
                printf("/");
            }            
            else
            {
                num++;
            }
        }
        printf("%c",ch);
    }
    printf("\nBlanks %d Tabs %d New Lines %d Others %d\n",blanks,tabs,newl,num);
}   