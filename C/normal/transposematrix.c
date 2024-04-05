#include <stdio.h>


int isSymetric(int n);

int main()
{
    int n;
    printf("Enter number of rows and columns\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    isSymetric(n);
}

int isSymetric(int n)
{
    int mat[n][n];
    int mat1[n][n];
    int k=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&mat[i][j]);
        }        
    }

    printf("The matrix is :- \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ",mat[i][j]);
        }
        printf("\n");        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat1[j][i] =  mat[i][j];
        }
    }

    printf("The transpose of the matrix is :- \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ",mat1[i][j]);
        }
        printf("\n");
    }
}