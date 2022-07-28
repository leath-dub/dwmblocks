#include <stdio.h>
#include <time.h>
#include <string.h>

typedef enum bool {
    False,
    True
} bool;

// const uint16_t date_msk = day | month | year;
enum date_fmt { day, month, year };
const unsigned int date_len = 3;
const char date_delim = '-';
const bool show_date = False;

// const uint16_t time_msk = hour | minute | second;
enum time_fmt { hour, minute, second };
const unsigned int time_len = 2;
const char time_delim = ':';
const bool show_time = True;

void
print_itoa(int n)
{
    char str[32];
    int len;
    char *ptr = str;
    for (unsigned int iter = 10, cond = 1; cond;
            cond = (n % iter < n), iter *= 10, ++ptr)
        sprintf(ptr, "%c", (char)(((n % iter) / (iter / 10)) + 0x30));

    len = strlen(str);
    if (len <= 1) for (;len;--len) putchar('0');

    while (ptr-- != str) putchar(*ptr);
}

void
print_date(struct tm *time)
{
    for (unsigned int i = 0; i < date_len; ++i) {
        switch(i) {
            case day: print_itoa(time->tm_mday); break;
            case month: print_itoa(time->tm_mon + 1); break;
            case year: print_itoa(time->tm_year + 1900); break;
        } if ((i < date_len - 1) && putchar(date_delim));
    }
}

void
print_time(struct tm *time)
{
    for (unsigned int i = 0; i < time_len; ++i) {
        switch(i) {
            case hour: print_itoa(time->tm_hour); break;
            case minute: print_itoa(time->tm_min); break;
            case second: print_itoa(time->tm_sec); break;
        } if ((i < time_len - 1) && putchar(time_delim));
    }
}

int
main(void)
{
    time_t _time = time(NULL);
    struct tm *time = localtime(&_time);
    fputs(" ", stdout);
    if (show_date) print_date(time);
    if (show_time & show_date) putchar(' ');
    if (show_time) print_time(time);
    return 0;
}
