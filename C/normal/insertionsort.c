 #include <math.h>

#include <stdio.h>

int n,uwu=1;

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printf("Case %d:-  ",uwu);
        uwu++;
        printArray(arr, n);
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

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}