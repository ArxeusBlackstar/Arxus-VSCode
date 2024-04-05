 #include <stdio.h>


int nn;

int addvector(int *a, int *b)
{
    int cc[nn];
    char gg = 'i';
    for (int i = 0; i < nn; i++)
    {
        cc[i] = *(a+i) + *(b+i);
        printf("+ %d%c ",cc[i],gg);
        gg++;
    }
}

int main()
{
    printf("Enter the maximum dimensions \n");
    scanf("%d",&nn);
    int aa[nn],bb[nn];
    printf("Enter one vector \n");
    for (int i = 0; i < nn; i++)
    {
        scanf("%d",&aa[i]);
    }
    printf("Enter the other vector \n");
    for (int i = 0; i < nn; i++)
    {
        scanf("%d",&bb[i]);
    }
    
    addvector(&aa[0],&bb[0]);
}