 #include <stdio.h>

int main()
{
    int n1, n2;
    printf("Enter the number of elements in Equation 1 ");
    scanf("%d", &n1);
    printf("Enter the number of elements in Equation 2 ");
    scanf("%d", &n2);

    int pow1[n1];
    int pow2[n1];

    int cof1[n2];
    int cof2[n2];

    int pow[n1 + n2];
    int cof[n1 + n2];

    printf("Enter the elements in Equation 1\n ");

    for (int i = 0; i < n1; i++)
    {
        printf("Enter the coefficient:- ");
        scanf("%d", &cof1[i]);

        printf("Enter the power:- ");
        scanf("%d", &pow1[i]);
    }

    printf("Enter the elements in Equation 2\n ");

    for (int i = 0; i < n2; i++)
    {
        printf("Enter the coefficient:- ");
        scanf("%d", &cof2[i]);

        printf("Enter the power:- ");
        scanf("%d", &pow2[i]);
    }

    for (int i = 0; i < n1; i++)
    {
        pow[i] = 0;
        cof[i] = 0;
    }

    int k = 0;

    for (int i = 0; i < n1; i++)
    {
        int p = 0;
        for (int j = 0; j < k; j++)
        {
            if (pow[j] == pow1[i])
            {
                cof[j] = cof1[i] + cof[j];
                p++;
            }
        }
        if (p == 0)
        {
            pow[k] = pow1[i];
            cof[k] = cof1[i];
            k++;
        }
    }

    for (int i = 0; i < n2; i++)
    {
        int p = 0;
        for (int j = 0; j < k; j++)
        {
            if (pow[j] == pow2[i])
            {
                cof[j] = cof2[i] + cof[j];
                p++;
            }
        }
        if (p == 0)
        {
            pow[k] = pow2[i];
            cof[k] = cof2[i];
            k++;
        }
    }

    printf("The added equation is :-\n ");

    for (int i = 0; i < k; i++)
    {
        printf("%d*x^%d + ", cof[i], pow[i]);
    }
    printf("\n");
}