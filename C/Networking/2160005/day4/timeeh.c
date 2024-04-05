#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *timmeh()
{
    long long int timsec, timmin, timewhour, timday, timeyawr;
    int secnow, minnow, hrnow, dynow, yrnow;
    char month[12][12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    static char date[2000];
    int monthay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    timsec = time(NULL);

    timmin = timsec / 60;

    timewhour = timsec / (60 * 60);

    timday = timewhour / 24;

    long long a = ((timday * 3) / (4 * 365));

    long long b = ((timday * 1) / (4 * 366));

    timeyawr = a + b;

    yrnow = timeyawr + 1970;

    dynow = timday - (((timeyawr * 3 * 365) / 4) + ((timeyawr * 366) / 4));
    dynow--;

    hrnow = timewhour - (timday * 24);

    minnow = timmin - (timewhour * 60);

    secnow = timsec - (timmin * 60);

    int day = dynow, num = 0;
    if (yrnow % 4 == 0)
    {
        monthay[1] = 29;
    }
    while (day > monthay[num])
    {
        day = day - monthay[num];
        num++;
    }
    day++;

    sprintf(date, "Its the year -> %d / month -> %s / days -> %d / date -> %d / hours -> %d / minutes -> %d / seconds -> %d /", yrnow, month[num], dynow, day, hrnow, minnow, secnow);

    return date;
}

int main()
{
    char *myString = timmeh();
    printf("%s\n", myString);
    return 0;
}