#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100
struct Graph
{
    int numVertices;
    int adjMatrix[MAX][MAX];
};
int min(int a, int b)
{
    return (a < b) ? a : b;
}
void addEdge(struct Graph *graph, int vertex1, int vertex2, int weight)
{
    if (graph->adjMatrix[vertex1][vertex2] != 0 && graph->adjMatrix[vertex1][vertex2] <= weight)
        return;
    if (vertex1 == vertex2)
        return;
    graph->adjMatrix[vertex1][vertex2] = min(weight, graph->adjMatrix[vertex1][vertex2]);
    graph->adjMatrix[vertex2][vertex1] = min(weight, graph->adjMatrix[vertex1][vertex2]);
}
void dijkstra(struct Graph *graph, int source)
{
    int dist[MAX], visited[MAX];
    int count, minDist, nextvertex;
    for (int i = 0; i < graph->numVertices; i++)
    {
        dist[i] = graph->adjMatrix[source][i];
        visited[i] = 0;
    }
    dist[source] = 0;
    visited[source] = 1;
    for (count = 1; count < graph->numVertices - 1; count++)
    {
        minDist = INT_MAX;
        for (int i = 0; i < graph->numVertices; i++)
            if (dist[i] < minDist && !visited[i])
            {
                minDist = dist[i];
                nextvertex = i;
            }
        visited[nextvertex] = 1;
        for (int i = 0; i < graph->numVertices; i++)
            if (!visited[i])
                if (minDist + graph->adjMatrix[nextvertex][i] < dist[i])
                    dist[i] = minDist + graph->adjMatrix[nextvertex][i];
    }
    printf("Shortest distances from source vertex %d:\n", source);
    printf("Vertex\tDistance\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        printf("%d\t", i);
        (dist[i] > INT_MAX / 4) ? printf("INF\n") : printf("%d\n", dist[i]);
    }
}
int main()
{
    struct Graph graph;
    int numEdges, vertex1, vertex2, weight, source;
    printf("Enter the number of vertices: ");
    scanf("%d", &graph.numVertices);
    printf("\nThe vertices are numbered from 0 to %d\n", graph.numVertices - 1);
    for (int i = 0; i < graph.numVertices; i++)
        for (int j = 0; j < graph.numVertices; j++)
            graph.adjMatrix[i][j] = INT_MAX / 2;
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    printf("Enter set of two vertices you want to join with an edge followed by corresponding weight:\n");
    for (int i = 0; i < numEdges; i++)
    {
        scanf("%d %d %d", &vertex1, &vertex2, &weight);
        addEdge(&graph, vertex1, vertex2, weight);
    }
    printf("Enter the source : ");
    scanf("%d", &source);
    dijkstra(&graph, source);
    return 0;
}