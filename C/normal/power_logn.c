#include <stdio.h>

int fastPower (int X, int n)
{
	int result=1;
	while (n)
	{
		if (n%2)
			result*= X;
		X*= X;
		n/=2;
	}
	return result;
}

int main()
{
	int x, n;
	printf("Enter the value of x and n :\n");
	scanf("%d%d",&x,&n);
	printf("Result : %d\n", fastPower(x, n));
	return 0;
}