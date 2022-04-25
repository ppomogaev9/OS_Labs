#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ERROR -1

int main()
{
    time_t now;

    (void)time(&now);

    if (setenv("TZ", "America/Los_Angeles", 1) == ERROR) {
        perror("changing TZ entailed error");
        return ERROR;
    }

    char* date_string = ctime(&now);
    if (date_string == NULL) {
        perror("ctime terminated with error");
        return ERROR;
    }

    printf("%s", date_string);

    struct tm *sp;

    sp = localtime(&now);
    if (sp == NULL) {
        perror("invoking localtime entailed error");
        return ERROR;
    }

    printf("%d/%d/%02d %d:%02d %s\n",
        sp->tm_mon + 1, sp->tm_mday,
        sp->tm_year, sp->tm_hour,
        sp->tm_min, tzname[sp->tm_isdst]);
    return 0;
}
