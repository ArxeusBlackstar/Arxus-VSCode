#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX 100


void matrixCO(int p[], int m[][MAX], int s[][MAX], int n)
{
    int i, l, j, k, q;
    for (i = 0; i < n; i++)
        m[i][i] = 0;
    for (l = 2; l <= n; l++)
        for (i = 0; i < n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
}
void printParenthesis(int s[][MAX], int i, int j)
{
    if (i == j)
        printf("M%d", i);
    else
    {
        printf("(");
        printParenthesis(s, i, s[i][j]);
        printParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}
int main()
{
    int p[MAX], m[MAX][MAX], s[MAX][MAX];
    int n;
    printf("Enter the number of elements in p : ");
    scanf("%d", &n);
    printf("Enter the elements in p :\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    matrixCO(p, m, s, n);
    printf("No. : %d", m[1][n - 1]);
    printf("\nParenthesis : ");
    printParenthesis(s, 1, n - 1);
    printf("\n");
    return 0;
}