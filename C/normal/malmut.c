/* #include <limits.h>
#include <stdio.h>

int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;

    for (k = i; k < j; k++)
    {
        count = MatrixChainOrder(p, i, k)
                + MatrixChainOrder(p, k + 1, j)
                + p[i - 1] * p[k] * p[j];
 
        if (count < min)
            min = count;
    }

    return min;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int N = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum number of multiplications is %d ",
           MatrixChainOrder(arr, 1, N - 1));
    getchar();
    return 0;
} */

#include <stdio.h>
#define MAX 10

int arr[MAX];

struct mut
{
    int row;
    int column;
};

struct mut mal[MAX];

int main()
{
    printf("Enter the number of elements in the array \n");
    int num;
    scanf("%d",&num);
    
    printf("Enter the elements in the array \n");    
    for (int i = 0; i < num; i++)
    {
        scanf("%d",&arr[i]);
    }

    int num1 = ((num-1)*2);
    int flag=0;

    for (int i = 0; i < (num - 1); i++)
    {
        mal[i].row = arr[flag];
        flag++;
        mal[i].column = arr[flag];
    }

    for (int i = 0; i < (num - 1); i++)
    {
        printf("%d %d",mal[i].row,mal[i].column);

        printf("\n");
    }
}