#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "/home/cathal/.dev/c-programs/config.h"

int timedate()
{
    FILE *ftime = fopen("/proc/driver/rtc", "r");
    char ch;
    int lineN = 0;
    int dash = 0;
    char time[20] = "";

    char year[20] = "-";
    char month[20] = "-";
    char day[20] = "";

    if (ftime == NULL)
        {
            printf("File is not available \n");
        }
        else
        {
            int count = 0;
            while (((ch = fgetc(ftime)) != EOF) && (lineN != 2))
            {
                if (ch == '\n')
                {
                    lineN++;
                }
                if ((count > 10) && (count < 16))
                {
                    strncat(time, &ch, 1); 
                }
                if (count > 30)
                {
                    if (ch == '-')
                    {
                        dash++;
                    }
                    if (dash == 0)
                    {
                        if ((ch != '\n') && (ch != '-'))
                        {
                            strncat(year, &ch, 1); 
                        }
                    }
                    if (dash == 1)
                    {
                        if ((ch != '\n') && (ch != '-'))
                        {
                            strncat(month, &ch, 1); 
                        }   
                    }
                    if (dash == 2)
                    {
                        if ((ch != '\n') && (ch != '-'))
                        {
                            strncat(day, &ch, 1); 
                        }
                    }
                }
                count++;
            }
        } 
        if (onlytime == 1)
        {
            printf(" %s", time);
        }
        else
        {
            printf(" %s%s%s %s", day, month, year, time);
        }
        fclose(ftime);
        return 0;
}

int main(void)
{
    timedate();
}

