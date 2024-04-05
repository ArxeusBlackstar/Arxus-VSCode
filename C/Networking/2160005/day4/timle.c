#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    long long int timsec, timmin, timewhour, timday, timeyawr;
    int secnow, minnow, hrnow, dynow, yrnow;
    char month[12][12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    char date[2000];
    int monthay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    time_t currentTime = time(NULL);
    printf("Current time is %ld \n", currentTime);

    timsec = time(NULL);
    printf("Seconds from 1970 to now %ld \n", timsec);  

    timmin = timsec / 60;
    printf("Minutes from 1970 to now %ld \n", timmin);

    timewhour = timsec / (60 * 60);
    printf("Hours from 1970 to now %ld \n", timewhour);

    timday = timewhour / 24;
    printf("Days from 1970 to now %ld \n", timday);

    long long a = ((timday * 3) / (4 * 365));
    printf("Normal Years from 1970 %ld \n", a);

    long long b = ((timday * 1) / (4 * 366));
    printf("Leap Years from 1970 %ld \n", b);

    timeyawr = a + b;
    printf("Total Years from 1970 %ld \n", timeyawr);

    yrnow = timeyawr + 1970;
    printf("Year now %d \n", yrnow);

    dynow = timday - (((timeyawr * 3 * 365) / 4) + ((timeyawr * 366) / 4));
    dynow--;
    printf("Days now %d \n", dynow);

    hrnow = timewhour - (timday * 24);
    printf("Hour now %d \n", hrnow);

    minnow = timmin - (timewhour * 60);
    printf("Minutes now %d \n", minnow);

    secnow = timsec - (timmin * 60);
    printf("Seconds now %d \n", secnow);

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
    printf("Month now is %s \n", month[num]);

    sprintf(date, "Its the year -> %d / month -> %s / days -> %d / date -> %d / hours -> %d / minutes -> %d / seconds -> %d /", yrnow, month[num], dynow, day, hrnow, minnow, secnow);
    printf("%s", date);
}