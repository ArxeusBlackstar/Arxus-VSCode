#include <stdio.h>

int power(int x, int n)
{
	int result = 1;
	while (n--)
		result*= x;
	return result;
}

int main()
{
	int x, n;
	printf("Enter the value of x and n :\n");
	scanf("%d%d",&x,&n);
	printf("Result : %d\n", power(x, n));
	return 0;
}