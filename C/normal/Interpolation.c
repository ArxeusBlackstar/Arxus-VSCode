#include <stdio.h>

int n, x;

int interpolationSearch(int arr[], int lo, int hi, int x)
{
    int pos;

    if (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {

        pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));

        if (arr[pos] == x)
        {
            return pos;
        }

        if (arr[pos] < x)
        {
            return interpolationSearch(arr, pos + 1, hi, x);
        }

        if (arr[pos] > x)
        {
            return interpolationSearch(arr, lo, pos - 1, x);
        }
    }
    return -1;
}

int main()
{
    printf("Enter the number of elements :-  ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of array \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter what you are looking for \n");
    scanf("%d", &x);
    int spandex = interpolationSearch(arr, 0, n - 1, x);

    if (spandex != -1)
    {
        printf("Element found at spandex %d", spandex);
    }
    else
    {
        printf("Element not found.");
    }
    return 0;
}