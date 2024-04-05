#include <stdio.h>

long n1 = 0, n2 = 1, sum = 0, uwu = 1;
long fibo(long n);

long main()
{
    long n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    printf("\n%d \n%d \n", 0, 1);
    fibo(n - 2);
    uwu++;
    printf("\n Comparisons :- : %d", uwu);
    return 0;
}

long fibo(long n)
{
    if (n > 0)
    {
        uwu++;
        sum = n1 + n2;
        n1 = n2;
        n2 = sum;
        printf("%d \n", sum);
        fibo(n - 1);
    }
}