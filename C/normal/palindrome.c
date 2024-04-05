#include<stdio.h>

int main()
{
    int n,p=0,d=0,k=0,or=0,sum=0;
    printf("Enter the number\n");
    scanf("%d",&n);
    or = n;
    while (n>0)
    {
        d = (int) n%10;
        printf("digit %d\n",d);
        k++;
        sum = sum + d;
        p = (p*10) + d;
        n = (int) n/10;
    }
    printf("Palin %d\n",p);
    printf("Number of digits %d\n",k);
    printf("Sum of digits %d\n",sum);
    if (p == or)
    {
        printf("Palindrome");
    }
    else
    {
        printf("Nope");
    }
    return 0;    
}