#include <stdio.h>
#define MAX 10
struct node
{
    int data;
    int numnei;
    int nei[MAX];
};

struct node Arr[MAX];

void BFS(int num, int start)
{
    int vis[num];
    int que[num];
    int fr = 0, rr = 0, flag = 0;

    vis[start] = 1;
    que[rr] = start;
    rr++;

    while (fr != rr)
    {
        printf("%d -> ", que[fr]);
        flag = que[fr];
        fr++;

        for (int i = 0; i < Arr[flag].numnei; i++)
        {
            int a = Arr[flag].nei[i];

            if (vis[a] != 1)
            {
                vis[a] = 1;
                que[rr] = a;
                rr++;
            }
        }
    }
}

void DFS(int num, int start)
{
    int vis[num];
    int stack[num];
    int top = 0, flag = 0;

    for (int i = 0; i < num; i++)
    {
        vis[num] = 0;
    }
    vis[start] = 1;
    stack[top] = start;
    top++;

    while (top > 0)
    {
        printf("%d -> ", stack[top - 1]);
        flag = stack[top - 1];
        top--;

        for (int i = 0; i < Arr[flag].numnei; i++)
        {
            int a = Arr[flag].nei[i];

            if (vis[a] != 1)
            {
                vis[a] = 1;
                stack[top] = a;
                top++;
            }
        }
    }
}

void main()
{
    int num, aa, bb, cc, flag = 0, numv = 0;

    printf("Enter the number of edges :- ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        Arr[i].numnei = 0;
    }

    for (int i = 0; i < num; i++)
    {
        printf("\n Edge %d \n", i + 1);
        scanf("%d", &aa);
        scanf("%d", &bb);

        Arr[aa].nei[Arr[aa].numnei] = bb;
        if (Arr[aa].numnei == 0)
        {
            numv++;
        }
        
        Arr[aa].numnei++;

    }

    /*int num1;
    for (int i = 0; i < numv; i++)
    {
        printf("\n");
        printf("Node %d :- \n", i);
        num1 = Arr[i].numnei;

        printf("The neighbours are :- ");
        for (int j = 0; j < num1; j++)
        {
            printf("%d , ", Arr[i].nei[j]);
        }
        printf("\n");
    }*/

    printf("Enter 1 for BFS 2 for DFS :- ");
    int ch;
    scanf("%d", &ch);

    printf("Enter the node to start from :- ");
    int start;
    scanf("%d", &start);

    if (ch == 1)
    {
        BFS(num, start);
    }
    else if (ch == 2)
    {
        DFS(numv, start);
    }
}