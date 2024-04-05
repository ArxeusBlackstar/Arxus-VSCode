#include <stdio.h>
#include <math.h>
#include <string.h>

long int conv1(long int num, long int bas);
long int conv2(long int num, long int bas);

long int sum = 1, n;

int l = 0;
char hex[1000];

int dechex(int n);
int hexdec(int n);
char conv(int n);

int main()
{
    int ch;
    do
    {
        printf("Enter\n 1 for binary to decimal\n 2 for binary to octal\n 3 for binary to hexademical\n 4 for decimal to binary\n 5 for decimal to octal\n 6 to decimal to hexadecimal\n 7 for octal to binary\n 8 for octal to decimal\n 9 for octal to hexadecimal\n 10 for hexadecimal to binary\n 11 for hexadecimal to decimal\n 12 to hexadecimal to octal\n");
        scanf("%d", &ch);
        printf("Enter the number\n");
        scanf("%d", &n);
        switch (ch)
        {
        case 1:
            conv1(n, 2);
            printf("Binary %ld\nDecimal %ld", n, sum);
            break;

        case 2:
            conv1(n, 2);
            conv2(sum, 8);
            sum = (long int)sum / 10;
            printf("Binary %ld\nOctal %ld", n, sum);
            break;

        case 3:
            conv1(n, 2);
            dechex(sum);
            printf("Hexadecimal of %d is ", n);
            for (int i = l - 1; i >= 0; i--)
            {
                printf("%c", hex[i]);
            }
            break;

        case 4:
            conv2(n, 2);
            printf("Decimal %ld\nBinary %ld", n, sum);
            break;

        case 5:
            conv2(n, 8);
            printf("Decimal %ld\nOctal %ld", n, sum);
            break;

        case 6:
            dechex(n);
            printf("Hexadecimal of %d is ", n);
            for (int i = l - 1; i >= 0; i--)
            {
                printf("%c", hex[i]);
            }
            break;

        case 7:
            conv1(n, 8);
            conv2(sum, 2);
            sum = (long int)sum / 10;
            printf("Octal %ld\nBinary %ld", n, sum);
            break;

        case 8:
            conv1(n, 8);
            printf("Octal %ld\nDecimal %ld", n, sum);
            break;

        case 9:
            conv1(n, 8);
            dechex(sum);
            printf("Hexadecimal of %d is ", n);
            for (int i = l - 1; i >= 0; i--)
            {
                printf("%c", hex[i]);
            }
            break;

        case 10:
            hexdec(n);
            conv2(sum, 2);
            sum = (int)sum / 10;
            printf("Binary equivalent is %ld", sum);
            break;

        case 11:
            hexdec(n);
            printf("Decimal equivalent is %ld", sum);
            break;

        case 12:
            hexdec(n);
            conv2(sum, 8);
            sum = (int)sum / 10;
            printf("Octal equivalent is %ld", sum);
            break;

        default:
            printf("Try Again");
            break;
        }
        printf("\nEnter 0 to exit\n");
        scanf("%d", &ch);
        sum = 1;
    } while (ch > 0);
}

long int conv2(long int num, long int bas)
{
    long int sav = num;
    int d = 0;
    while (sav > 0)
    {
        d = (int)sav % bas;
        sav = (int)sav / bas;
        sum = sum * 10 + d;
    }
    sav = sum;
    sum = 0;
    while (sav > 0)
    {
        d = (int)sav % 10;
        sav = (int)sav / 10;
        sum = sum * 10 + d;
    }
    sum = (long int)sum / 10;
}

long int conv1(long int num, long int bas)
{
    long int sav = num;
    int d = 0, p = 0;
    sum = 0;
    while (sav > 0)
    {
        d = (int)sav % 10;
        sav = (int)sav / 10;
        sum = (long int)sum + (d * pow(bas, p));
        p++;
    }
    p = 0;
}

int dechex(int n)
{
    int d = 0;
    char j = ' ';
    if (n > 0)
    {
        d = n % 16;
        hex[l] = conv(d);
        l++;
        n = n / 16;
        dechex(n);
    }
}

char conv(int n)
{
    char j = ' ';
    int i;
    if (n > 9)
    {
        for (i = 10, j = 'A'; j < 'G'; i++, j++)
        {
            if (n == i)
            {
                return j;
            }
        }
    }
    else
    {
        for (i = 1, j = '1'; i < 10; i++, j++)
        {
            if (n == i)
            {
                return j;
            }
        }
    }
}

int hexdec(int n)
{
    char num[1000];
    int d = 0, p = 0, yup = 0;
    printf("Enter the hexadecimal number now ");
    scanf("%s", &num);
    p = strlen(num);
    p = p - 1;

    for (int i = 0; i < strlen(num); i++)
    {
        if (num[i] >= '0' && num[i] <= '9')
        {
            d = (int)num[i];
            d = d - 48;
        }
        if ((num[i] >= 'A') && (num[i] <= 'F'))
        {
            d = (int)num[i];
            d = d - 55;
        }
        yup = yup + (d * pow(16, p));
        p--;
    }
    sum = yup;
}