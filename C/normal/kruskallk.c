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

int find(int parent[], int vertex)
{
    if (parent[vertex] == -1)
        return vertex;
    return find(parent, parent[vertex]);
}

void union_nodes(int parent[], int rank[], int x, int y)
{
    int x_root = find(parent, x);
    int y_root = find(parent, y);

    if (x_root == y_root)
        return;

    if (rank[x_root] < rank[y_root])
        parent[x_root] = y_root;
    else if (rank[x_root] > rank[y_root])
        parent[y_root] = x_root;
    else
    {
        parent[y_root] = x_root;
        rank[x_root]++;
    }
}

void kruskal()
{
    int parent[MAX];
    int rank[MAX] = {0};

    // Initialize all vertices as separate subsets with single elements
    for (int i = 0; i < MAX; i++)
        parent[i] = -1;

    int count = 0;
    int total_weight = 0;

    printf("Minimum Spanning Tree Edges: \n");
    for (int i = 0; i < num; i++)
    {
        int x = find(parent, Arr[i].node1);
        int y = find(parent, Arr[i].node2);

        // Add the edge to the minimum spanning tree if it doesn't create a cycle
        if (x != y)
        {
            printf("%d %d %d \n", Arr[i].node1, Arr[i].node2, Arr[i].weight);
            total_weight += Arr[i].weight;
            union_nodes(parent, rank, x, y);
            count++;
        }

        // Stop when we have added (V-1) edges
        if (count == MAX - 1)
            break;
    }

    printf("Total weight of the minimum spanning tree: %d \n", total_weight);
}

int main()
{
    input();
    sort();
    kruskal();

    return 0;
}