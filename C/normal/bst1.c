#include <stdio.h>
#include <stdlib.h>
int flag;
struct Node
{
    int data;
    struct Node *nextl;
    struct Node *nextr;
};

struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->nextl = temp->nextr = NULL;
    return temp;
}
struct Node *input(struct Node *Node, int key)
{
    if (Node == NULL)
    {
        return newNode(key);
    }
    if (key < Node->data)
    {
        Node->nextl = input(Node->nextl, key);
    }
    else
    {
        Node->nextr = input(Node->nextr, key);
    }
    return Node;
}

void inorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->nextl);
    printf("%d ->", root->data);
    inorderTraversal(root->nextr);
}

void preorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ->", root->data);
    preorderTraversal(root->nextl);
    preorderTraversal(root->nextr);
}

void postorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->nextl);
    postorderTraversal(root->nextr);
    printf("%d ->", root->data);
}

int search(struct Node *roote, int dat)
{
    do
    {
        if (roote->data > dat)
        {
            roote = roote->nextl;
        }
        if (roote->data < dat)
        {
            roote = roote->nextr;
        }
        if (roote->data == dat)
        {
            printf("Found\n");
            return 0;
        }
    } while (roote->nextl != NULL && roote->nextr != NULL); //(roote != NULL);
    printf("Not Found\n");
}

void main()
{
    int num, a = 1, ch, rot, se;
    struct Node *root;
    root = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the root  ");
    scanf("%d", &rot);
    root->data = rot;
    root->nextl = NULL;
    root->nextr = NULL;

    while (a == 1)
    {
        printf("Enter :-\n 1 to input \n 2 to search \n 3 to display \n");
        scanf("%d", &ch);

        if (ch == 1)
        {
            printf("Enter the number  ");
            scanf("%d", &num);
            root = input(root, num);
        }
        else if (ch == 2)
        {
            printf("Enter the number  ");
            scanf("%d", &se);
            search(root, se);
        }
        else if (ch == 3)
        {
            int ch1;
            printf("Enter :-\n 1 to inorder \n 2 to preorder \n 3 to postorder\n");
            scanf("%d", &ch1);
            if (ch1 == 1)
            {
                printf("\nInorder traversal \n");
                inorderTraversal(root);
            }
            else if (ch1 == 2)
            {
                printf("\nPreorder traversal \n");
                preorderTraversal(root);
            }
            else if (ch1 == 3)
            {
                printf("\nPostorder traversal \n");
                postorderTraversal(root);
            }
            printf("\n");
        }
        else
        {
            a++;
        }
    }
}