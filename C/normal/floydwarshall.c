#include <stdio.h>
#define V 4
#define INF 999999
int min(int a, int b)
{
    return (a < b) ? a : b;
}
void addEdge(int D[][V], int vertex1, int vertex2, int weight)
{
    if (D[vertex1][vertex2] != 0 && D[vertex1][vertex2] <= weight)
        return;
    if (vertex1 == vertex2)
        return;
    D[vertex1][vertex2] = D[vertex2][vertex1] = min(weight, D[vertex1][vertex2]);
}
void floydWarshall(int D[][V])
{
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            printf("%d\t", D[i][j]);
        printf("\n");
    }
}
int main()
{
    int vertex1, vertex2, weight, numEdges, D[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            D[i][j] = (i == j) ? 0 : INF;
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    printf("Enter the set of two vertices you want to join with an edge followed by the corresponding weight:\n");

    for (int i = 0; i < numEdges; i++)
    {
        scanf("%d%d%d", &vertex1, &vertex2, &weight);
        addEdge(D, vertex1, vertex2, weight);
    }
    floydWarshall(D);
    return 0;
}