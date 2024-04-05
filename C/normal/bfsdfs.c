#include <stdio.h>

struct node
{
    int data;
    int numnei;
    int nei[10];
};

struct node Arr[10];

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
        vis[num] = 0;
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
    int num, num1;

    printf("Enter the number of nodes ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("\n");
        printf("Node %d :- \n", i);
        /*printf("Enter the data of the node - ");
        scanf("%d", &Arr[i].data);*/

        printf("Enter the number of neighbours - ");
        scanf("%d", &num1);
        Arr[i].numnei = num1;

        printf("Enter the neighbours \n");
        for (int j = 0; j < num1; j++)
        {
            scanf("%d", &Arr[i].nei[j]);
            if (Arr[i].nei[j] > num)
            {
                printf("Invalid input, try again");
                j--;
            }
        }
    }

    for (int i = 0; i < num; i++)
    {
        printf("\n");
        printf("Node %d :- \n", i + 1);
        printf("data of the node is - %d \n", Arr[i].data);
        num1 = Arr[i].numnei;

        printf("The neighbours are :- ");
        for (int j = 0; j < num1; j++)
        {
            printf("%d , ", Arr[i].nei[j]);
        }
        printf("\n");
    }

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
        DFS(num, start);
    }
}