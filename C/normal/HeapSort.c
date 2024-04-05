#include <stdio.h>

int n,uwu=1;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }        
    printf("\n");
}

void hippy(int arr[], int N, int i)
{
    int lar = i;
    int nextl = 2 * i + 1;
    int nextr = 2 * i + 2;

    if (nextl < N && arr[nextl] > arr[lar])
    {
        lar = nextl;
    }
    if (nextr < N && arr[nextr] > arr[lar])
    {
        lar = nextr;
    }
    if (lar != i)
    {

        swap(&arr[i], &arr[lar]);
        hippy(arr, N, lar);
    }
}

void cheapsort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        hippy(arr, N, i);
    }
    for (int i = N - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        printf("Case %d:-  ",uwu);
        uwu++;
        printArray(arr, n);
        hippy(arr, i, 0);
    }
}

int main()
{
    printf("Enter the number of elements :-  ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements :-  \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    cheapsort(arr, n);
    printf("Sorted array is\n");
    printArray(arr, n);
}