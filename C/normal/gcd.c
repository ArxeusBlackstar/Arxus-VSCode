#include <stdio.h>

int gcd(int n1, int n2);
int main() 
{
    int n1, n2, hcf;
    printf("Enter two numbers ");
    scanf("%d %d", &n1, &n2);
    hcf = gcd(n1,n2);
    printf("G.C.D of %d and %d is %d.", n1, n2, hcf);
    return 0;
}

int gcd(int n1, int n2) {
    if (n2 != 0)
    {
        return gcd(n2, n1 % n2);
    }
    else
    {
        return n1;
    }
}