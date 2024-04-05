 #include <stdio.h>


int main()
{
    int n;
    printf("Enter the number of elements :-  ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements :-  \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");

    int stack[n];
    int top = -1;

    int l = 0, h = n - 1;

    stack[++top] = l;
    stack[++top] = h;

    int uwu=1;

    while (top >= 0)
    {
        h = stack[top--];
        l = stack[top--];

        int x = arr[h];
        int i = (l - 1);

        for (int j = l; j <= h - 1; j++)
        {
            if (arr[j] <= x)
            {
                i++;
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }

        int t = arr[i + 1];
        arr[i + 1] = arr[h];
        arr[h] = t;

        int p = i + 1;

        if (p - 1 > l)
        {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        if (p + 1 < h)
        {
            stack[++top] = p + 1;
            stack[++top] = h;
        }

        printf("Case %d :-  ",uwu);

        for (int i = 0; i < n; ++i)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        uwu++;
    }

    printf("\nFinal Output:- \n");

    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
}