#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main()
{
    struct timeval t;

    gettimeofday(&t, NULL);
    printf("sec=%lld, usec=%lld\n", t.tv_sec, t.tv_usec);

    time_t now;
    now = time(0);
    printf("222: sec = %lld\n", (long long)now);
    struct tm *ptmNow = localtime(&now);
    char ctime[128] = {0};
    sprintf(ctime, "%4d-%2d-%2d %2d:%2d:%2d", 1900 + ptmNow->tm_year,1+ptmNow->tm_mon,ptmNow->tm_mday,ptmNow->tm_hour,ptmNow->tm_min,ptmNow->tm_sec);
    printf("standtime is %s\n", ctime);

    return 0;
}
