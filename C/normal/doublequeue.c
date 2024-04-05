 #include<stdio.h>

#define MAX 10
int main()
{
    int A[MAX];
    int ch,ch1,aa,size=0,a=1,fr=-1,rr=-1;
    while (a==1)
    {
        printf("Enter \n 1 for Push \n 2 for Pop \n 3 for display \n");
        scanf("%d",&ch);
        
        if (ch == 1)
        {
            if (size >= MAX)
            {
                printf("Overflow \n");
            }
            else
            {
                printf("Enter 1 for Ora 2 for Ana  ");
                scanf("%d",&ch1);
                printf("Enter the element  ");
                scanf("%d",&aa);
                if (ch1 == 1)
                {
                    if (fr == -1 && rr == -1)
                    {
                        fr=0;rr=0;
                    }
                    else if (fr == 0)
                    {
                        fr=MAX-1;
                    }
                    else
                    {
                        fr--;
                    }                     
                    A[fr] = aa;
                    size++;
                }
                if (ch1 == 2)
                {
                    if (fr == -1 && rr == -1)
                    {
                        fr=0;rr=0;
                    }
                    else if (rr == (MAX-1))
                    {
                        rr=0;
                    }
                    else
                    {
                        rr++;
                    }
                    A[rr] = aa;
                    size++;
                }
            }
        }
        
        else if (ch == 2)
        {
            if (size < 0)
            {
                printf("Underflow \n");
            }

            else
            {
                printf("Enter 1 for Ora 2 for Ana  ");
                scanf("%d",&ch1);

                if (ch1 == 2)
                {
                    printf("Rear end is %d \n", A[rr]);
                    if (fr == rr)
                    {
                        fr = -1;
                        rr = -1;
                    }
                    else if (rr == 0)
                    {
                        rr = MAX - 1;
                    }
                    else
                    {
                        rr--;
                    }                   
                }

                if (ch1 == 1)
                {
                    printf("Front end is %d \n", A[fr]);
                    if (fr == rr)
                    {
                        fr = -1;
                        rr = -1;
                    }
                    else
                    {
                        if (fr == MAX - 1)
                        {
                            fr = 0;
                        }
                        else
                        {
                            fr++;
                        }
                    }
                }
                size--;
            }
        }

        else if (ch == 3)
        {
            if (size < 0)
            {
                printf("Empty \n");
            }
            if (fr <= rr)
            {
                for (int i = fr; i <= rr; i++)
                {
                    printf("%d  ",A[i]);
                }
            }
            else
            {
                for (int i = fr; i < MAX; i++)
                {
                    printf("%d  ",A[i]);
                }

                for (int i = 0; i <= rr; i++)
                {
                    printf("%d  ",A[i]);
                }
            }
            printf("\n");
        }

        else
        {
            a = 0;
        }
    }
}

        