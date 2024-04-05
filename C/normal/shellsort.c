 #include <stdio.h>


int n, uwu = 1;

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void shellSort(int arr[], int n)
{
    for (int interval = n / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval)
            {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
            printf("Case %d:-  ", uwu);
            uwu++;
            printarr(arr, n);
        }
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
    shellSort(arr, n);
    printf("Sorted arr: \n");
    printarr(arr, n);
}