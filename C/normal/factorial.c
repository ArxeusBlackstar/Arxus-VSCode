#include<stdio.h>

#include<math.h>
int main()
{
    float n,fuc=1,i=0;
    printf("Enter a number\n");
    scanf("%f",&n);
    for ( i = 1; i <= n; i++)
    {
        fuc = fuc * i;
    }
    printf("%f",fuc);
    return 0;
}
       