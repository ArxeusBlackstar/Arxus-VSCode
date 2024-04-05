#include <stdio.h>

void towers(int, char, char, char);

int main()
{
    int num;

    printf("Enter the number of dicks : ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'A', 'C', 'B');
    return 0;
}
void towers(int num, char Tower1, char Tower2, char Tower3)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from %c to %c", Tower1, Tower2);
        return;
    }

    towers(num - 1, Tower1, Tower3, Tower2);
    printf("\n Move disk %d from %c to %c", num, Tower1, Tower2);
    towers(num - 1, Tower3, Tower2, Tower1);
}