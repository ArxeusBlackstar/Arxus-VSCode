#include<stdio.h>

#include<string.h>
int main()
{
    int nn,ch;
    char str1[1000];
    char str2[1000];
    printf("Enter\n1 for compare\n2 to concat\n3 to check palindrome\n");
    scanf("%d",&ch);

    if (ch == 1)
    {
        printf("Enter 1st string  ");
        scanf("%s",&str1);
        printf("Enter 2nd string  ");
        scanf("%s",&str2);
        for (int i = 0; i < 1000; i++)
        {
            int k = (int) (str1[i]-str2[i]);
            if (k != 0)
            {
                printf("%d",k);
                break;
            }
        }
    }

    if (ch == 2)
    {
        printf("Enter 1st string  ");
        scanf("%s",&str1);
        printf("Enter 2nd string  ");
        scanf("%s",&str2);
        int k = strlen(str1);
        int l = strlen(str2);
        int str[2000];
        for (int i = 0; i < k; i++)
        {
            str[i]=str1[i];
        }
        for (int i = 0; i < l; i++)
        {
            str[i+k]=str2[i];
        }
        for (int i = 0; i < l+k; i++)
        {
            printf("%c",str[i]);
        }
    }

    if (ch == 3)
    {
        printf("Enter string  ");
        scanf("%s",&str1);
        for (int i = 0,j = strlen(str1)-1; i < strlen(str1); i++,j--)
        {
            str2[j]=str1[i];
        }

        int k=0;

        for (int i = 0; i < strlen(str2); i++)
        {
            if (str1[i]!=str2[i])
            {
                k++;
            }
        }
        if (k==0)
        {
            printf("Palindrome");
        }
        else
        {
            printf("No");
        }
    }
}