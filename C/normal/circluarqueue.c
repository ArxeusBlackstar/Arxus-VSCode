#include<stdio.h>

#define MAX 3
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
                printf("Overflow \n");
            }
            else
            {
                if (fr == -1 && rr == -1)
                {
                    fr = 0;
                }
                if (rr == MAX-1)
                {
                    rr=0;
                }
                else
                {
                    rr++;
                }
                printf("Enter the element ");
                scanf("%d",&aa);
                A[rr] = aa;
                size++;
            }
        }

        else if (ch == 2)
        {
            if (size <= 0)
            {
                printf("Underflow \n");
            }
            printf("Element popped is :- %d \n",A[fr]);
            size--;

            if(fr == rr)
            {
                fr = -1;
                rr = -1;
            }
            else
            {
                if (fr == MAX-1)
                {
                    fr = 0;
                }
                else
                {
                    fr++;
                }
            }
        }

        else if (ch == 3)
        {
            if (size <= 0)
            {
                printf("Queue Empty");
            }
            if (fr <= rr)
            {
                for (int i = fr; i <= rr; i++)
                {
                    printf("%d  ",A[i]);
                }
            }
            else
            {
                for (int i = fr; i < MAX; i++)
                {
                    printf("%d  ",A[i]);
                }

                for (int i = 0; i <= rr; i++)
                {
                    printf("%d  ",A[i]);
                }
            }
            printf("\n");
        }

        else
        {
            a = 0;
        }
    }
}