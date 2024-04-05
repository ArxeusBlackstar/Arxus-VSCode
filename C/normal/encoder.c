#include<stdio.h>

#include<string.h>
int main()
{
    int l=0,n;
    char str[1000];
    
    printf("Enter the string\n");
    scanf("%[^\n]s",&str);
    printf("Enter the number\n");
    scanf("%d",&n);
    l = strlen(str);

    for (int i = 0; i < l; i++)
    {
        char ch=' ';
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            ch = str[i];
            for (int i = 0; i < n; i++)
            {
                ch++;
                if (ch > 'Z' && ch < 'a')
                {
                    ch = 'A';
                }
                else if(ch > 'z')
                {
                    ch = 'a';
                }                
            }
            str[i]=ch;
        }
    }
    printf("%s",str);
}