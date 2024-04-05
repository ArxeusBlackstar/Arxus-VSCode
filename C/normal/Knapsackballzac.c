#include <stdio.h>

struct cumred
{
	float pris;
	float wei;
	float priswei;
};

void swap(struct cumred *xp, struct cumred *yp)
{
	struct cumred temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void main()
{
	int n, max;
	printf("Enter the number of elements   -  ");
	scanf("%d", &n);
	struct cumred ivan[n];
	printf("Enter the maximum size  -  ");
	scanf("%d", &max);
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("Enter profit of %d  -  ", i + 1);
		scanf("%f", &ivan[i].pris);
		printf("Enter the weight of %d - ", i + 1);
		scanf("%f", &ivan[i].wei);
		ivan[i].priswei = (ivan[i].pris / ivan[i].wei);
		printf("\n");
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < (n - i - 1); j++)
		{
			if (ivan[j].priswei > ivan[j + 1].priswei)
			{
				swap(&ivan[j], &ivan[j + 1]);
			}
		}
	}

	int i = n - 1;
	float answer;
	while (max > 0)
	{
		if (ivan[i].wei < max)
		{
			max = max - ivan[i].wei;
			answer = answer + ivan[i].pris;
			i--;
		}
		else
		{
			answer = answer + (max * ivan[i].priswei);
			max = 0;
		}
	}
	printf("MAX PROFIT is - %f \n", answer);
}