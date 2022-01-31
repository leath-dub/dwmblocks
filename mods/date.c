#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

void date()
{
    FILE *fdate = fopen("/proc/driver/rtc", "r");
    char tmp[256];
    char time[5];
    char data[5][6];
    const char delim[2] = "-";
    char *token;
    for (int i = 0; i < 6; i++)
    {
        fscanf(fdate, "%s", &tmp); 
        switch(i)
        {
            case 2:
                sprintf(data[0], "%.5s", tmp);
                break;
            case 5:
                token = strtok(tmp, delim);
                int j = 1;
                while( token != NULL ) 
                {
                    sprintf(data[j], "%s", token);
                    token = strtok(NULL, delim);
                    j++;
                }
        }
    }
    switch(onlytime)
    {
        case 0:
            printf(" %s-%s-%s %s", data[3], data[2], data[1], data[0]);
            break;
        case 1:
            printf(" %s", data[0]);
    }
    fclose(fdate);
}
void main()
{
    date();
}
