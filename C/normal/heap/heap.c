#include <stdio.h>
#include <stdlib.h>

int n = 1000, uwu = 1;
int arr[1000];

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
    uwu++;
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
        hippy(arr, i, 0);
    }
}

int zmain(char *input, char *output)
{
    int sum = 0, flag = 0, ch = 1;
    FILE *filo = fopen(input, "w");

    for (int i = 0; i < n; i++)
    {
        int rando = rand() % 1000 + 1;
        fprintf(filo, "%d ", rando);
    }
    fclose(filo);

    for (int i = 0; i < n; i++)
    {
        arr[i] = 1;
    }
    
    FILE *filoi = fopen(input, "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(filo, "%d", &arr[i]);
    }
    fclose(filoi);
    

    uwu = 0;
    cheapsort(arr, n);

    printf("\n Number of comparisons is :- %d \n", uwu);

    FILE *filoo = fopen(output, "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(filoo, "%d ", arr[i]);
    }
    fclose(filoo);
}

int main()
{
    int sum = 0;
    zmain("input1", "output1");
    sum = sum + uwu;
    uwu = 0;
    zmain("input2", "output2");
    sum = sum + uwu;
    uwu = 0;
    zmain("input3", "output3");
    sum = sum + uwu;
    uwu = 0;
    zmain("input4", "output4");
    sum = sum + uwu;
    uwu = 0;
    zmain("input5", "output5");
    sum = sum + uwu;
    uwu = 0;

    int avg = sum / 5;

    printf("\n Average is :- %d \n", avg);
}