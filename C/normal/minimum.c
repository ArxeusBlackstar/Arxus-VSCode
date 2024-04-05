int min(int arr[], int len)
{
    int min = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[min] > arr[i])
        {
            min = i;
        }
    }
    return min;
}

void main()
{
    int arr[] = {1, 20, 40, 50, 60000, 70, 30, 40, 10, 234, 60};
    int a = min(arr, 10);
    printf("Min at %d", a + 1);
}
