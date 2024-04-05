#include<stdio.h>

#define MAX 10
int main()
{
    int A[MAX];
    int ch,aa,size=0,a=1,fr=-1,rr=-1;
    while (a==1)
    {
        printf("Enter \n 1 for Push \n 2 for Pop \n 3 for display \n");
        scanf("%d",&ch);
        
        if (ch == 1)
        {
            if (size >= MAX)
            {
                printf("Stack Overflow");
            }
            else
            {
                if (fr == -1 && rr == -1)
                {
                    fr=0;
                }
                rr++;
                printf("Enter the element");
                scanf("%d",&aa);
                A[rr] = aa;
                size++;
            }
        }

        else if (ch == 2)
        {
            if (size <= 0)
            {
                printf("Stack Underflow");
            }
            else
            {
                printf("Element popped is :- %d \n",A[fr]);
                fr++;
                size--;
            }
        }

        else if (ch == 3)
        {
            if (size <= 0)
            {
                printf("Empty Queue");
            }
            else
            {
                for (int i = fr; i <= rr; i++)
                {
                    printf("%d",A[i]);
                }
                printf("\n");
            }
        }
        else
        {
            a = 0;
        }
    }
}