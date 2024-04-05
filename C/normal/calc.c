 #include<stdio.h>

#include<math.h>
#include<conio.h>
int main()
{
    float n1,n2,ans=0;
    char ch,g;
    do
    {
        printf("Enter the first number \n");
        scanf("%f",&n1);
        printf("Enter the second number \n");
        scanf("%f",&n2);
        printf("Enter \n A to add \n S to substract \n M to multiply \n D to divide \n");
        fflush(stdin);
        scanf("%c",&ch);

        if (ch == 'a' || ch == 'A')
        {
            ans = n1+n2;
            printf("The sum is %f" , ans);
        }
        else if (ch == 's' || ch == 'S')
        {
            ans = n1-n2;
            printf("The differnce is %f" , ans);
        }
        else if (ch == 'm' || ch == 'M')
        {
            ans = n1*n2;
            printf("The product is %f" , ans);
        }
        else if (ch == 'd' || ch == 'D')
        {
            ans = n1/n2;
            printf("The quotient is %f" , ans);
        }
        printf("\nEnter Y to continue \n");
        fflush(stdin);
        scanf("%c",&g);
    }while (g=='Y'||g=='y');   
    return 0;
}