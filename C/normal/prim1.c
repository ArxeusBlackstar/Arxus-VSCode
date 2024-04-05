#include <stdio.h>
#include <stdbool.h>
#define MAX 10

struct node
{
    int weight;
    int node1;
    int node2;
};

int num;
struct node Arr[MAX];

int input()
{
    printf("Enter the number of lines: ");
    scanf("%d", &num);

    printf("Enter the edges:- \n");

    for (int i = 0; i < num; i++)
    {
        scanf("%d %d %d", &Arr[i].node1, &Arr[i].node2, &Arr[i].weight);
        printf("\n");
    }
}

void sort()
{
    for (int step = 0; step < num - 1; ++step)
    {
        for (int i = 0; i < num - step - 1; ++i)
        {
            if (Arr[i].weight > Arr[i + 1].weight)
            {
                struct node temp = Arr[i];
                Arr[i] = Arr[i + 1];
                Arr[i + 1] = temp;
            }
        }
    }
}

void prim(int start_vertex)
{
    bool visited[MAX] = {false};
    visited[start_vertex] = true;

    int count = 0;
    int total_weight = 0;

    printf("Minimum Spanning Tree Edges: \n");
    while (count < num - 1)
    {
        int min_weight = MAX;
        int min_index = -1;

        // Find the edge with the smallest weight that connects a visited vertex to an unvisited vertex
        for (int i = 0; i < num; i++)
        {
            if (visited[Arr[i].node1] && !visited[Arr[i].node2] && Arr[i].weight < min_weight)
            {
                min_weight = Arr[i].weight;
                min_index = i;
            }
            else if (!visited[Arr[i].node1] && visited[Arr[i].node2] && Arr[i].weight < min_weight)
            {
                min_weight = Arr[i].weight;
                min_index = i;
            }
        }

        if (min_index == -1)
        {
            // No edge found
            break;
        }

        // Add the edge to the minimum spanning tree
        printf("%d %d %d \n", Arr[min_index].node1, Arr[min_index].node2, Arr[min_index].weight);
        total_weight += Arr[min_index].weight;

        // Mark the connected vertices as visited
        visited[Arr[min_index].node1] = true;
        visited[Arr[min_index].node2] = true;

        count++;
    }

    printf("Total weight of the minimum spanning tree: %d \n", total_weight);
}

int main()
{
    input();
    sort();

    int start_vertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &start_vertex);

    prim(start_vertex);

    return 0;
}