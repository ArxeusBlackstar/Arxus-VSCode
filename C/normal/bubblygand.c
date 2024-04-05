#include <stdio.h>

void bubbleSort(int array[], int size)
{
    for (int step = 0; step < size - 1; ++step)
    {
        for (int i = 0; i < size - step - 1; ++i)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

void main()
{
    int arr[] = {1, 20, 40, 50, 60000, 70, 30, 40, 10, 234, 60};
    bubbleSort(arr, 11);
}