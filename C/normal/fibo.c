#include<stdio.h>   

int n1=0,n2=1,sum=0; 
int fibo(int n);

int main()
{    
    int n;    
    printf("Enter the number of elements: ");    
    scanf("%d",&n);    
    printf("Fibonacci Series: ");    
    printf("%d %d ",0,1);    
    fibo(n-2);
    return 0;  
}

int fibo(int n)
{      
    if(n>0)
    {    
         sum = n1 + n2;    
         n1 = n2;    
         n2 = sum;    
         printf("%d ",sum);    
         fibo(n-1);    
    }    
}    