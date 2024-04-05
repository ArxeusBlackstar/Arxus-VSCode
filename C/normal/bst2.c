#include <stdio.h>
#include <stdlib.h>
int flag;
struct node
{
    int data;
    struct node *nextl;
    struct node *nextr;
};

struct node *newnode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->nextl = temp->nextr = NULL;
    return temp;
}
struct node *input(struct node *node, int dat)
{
    if (node == NULL)
    {
        return newnode(dat);
    }
    if (dat < node->data)
    {
        node->nextl = input(node->nextl, dat);
    }
    else
    {
        node->nextr = input(node->nextr, dat);
    }
    return node;
}

void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->nextl);
    printf("%d ->", root->data);
    inorderTraversal(root->nextr);
}

void preorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ->", root->data);
    preorderTraversal(root->nextl);
    preorderTraversal(root->nextr);
}

void postorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->nextl);
    postorderTraversal(root->nextr);
    printf("%d ->", root->data);
}

int search(struct node *root, int dat)
{
    do
    {
        if (root->data > dat)
        {
            root = root->nextl;
        }
        if (root->data < dat)
        {
            root = root->nextr;
        }
        if (root->data == dat)
        {
            printf("Found\n");
            return 0;
        }
    } while (root->nextl != NULL && root->nextr != NULL);
    printf("Not Found\n");
}
struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    while (current && current->nextl != NULL)
    {
        current = current->nextl;
    }
    return current;
}
struct node *delet(struct node *root, int dat)
{
    if (root == NULL)
    {
        return root;
    }
    if (dat < root->data)
    {
        root->nextl = delet(root->nextl, dat);
    }
    else if (dat > root->data)
    {
        root->nextr = delet(root->nextr, dat);
    }
    else
    {
        // node with only one child or no child
        if (root->nextl == NULL)
        {
            struct node *temp = root->nextr;
            free(root);
            return temp;
        }
        else if (root->nextr == NULL)
        {
            struct node *temp = root->nextl;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->nextr);
        root->data = temp->data;
        root->nextr = delet(root->nextr, temp->data);
    }
    return root;
}

void main()
{
    int num, a = 1, ch, rot, se;
    struct node *root;
    root = (struct node *)malloc(sizeof(struct node));

    printf("Enter the root  ");
    scanf("%d", &rot);
    root->data = rot;
    root->nextl = NULL;
    root->nextr = NULL;

    while (a == 1)
    {
        printf("Enter :-\n 1 to input \n 2 to search \n 3 to display \n 4 to delete \n");
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
                printf("Inorder traversal \n");
                inorderTraversal(root);
            }
            else if (ch1 == 2)
            {
                printf("Preorder traversal \n");
                preorderTraversal(root);
            }
            else if (ch1 == 3)
            {
                printf("Postorder traversal \n");
                postorderTraversal(root);
            }
            printf("\n");
        }
        else if (ch == 4)
        {
            printf("Enter the number  ");
            scanf("%d", &se);
            root = delet(root, num);
        }
        else
        {
            a++;
        }
    }
}