#include<stdio.h>

#define MAX 4
int main()
{
    int A[MAX];
    int l=0,h=MAX-1,aa,m=0,x,a=0;

    printf("Enter the elements of array \n");
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d",&aa);
        A[i] = aa;
    }

    printf("Enter what you are looking for \n");
    scanf("%d",&x);

    for (int i = 0; i < MAX-1; i++)
    {
        for (int j = 0; j < MAX - i - 1; j++)
        {
            if (A[j] > A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }

    printf("Sorted array:- ");

    for (int i = 0; i < MAX; i++)
    {
        printf("%d  ",A[i]);
    }
    
    printf("\n");

    while (l<=h)
    {
        m = (int) (l+h)/2;
        if (A[m] == x)
        {
            printf("%d found at %d", x,m+1);
            a=1;
            break;
        }
        else if (A[m] < x)
        {
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }

    if (a != 1)
    {
        printf("Not found");
    }
}