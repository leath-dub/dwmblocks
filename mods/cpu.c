#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int jiff(int jiffies[2])
{
    FILE *fcpu = fopen("/proc/stat", "r");
    int total_jiffies = 0;
    int work_jiffies = 0;
    int columns = 0;
    char ch;
    int count = 0;
    int junk;
    char build[20];
    while (((ch = fgetc(fcpu)) != EOF ) && (count != 4))
    {
        count++;
    }
    count = 0;
    while (((ch = fgetc(fcpu)) != EOF ) && (ch != '\n'))
    {
        strncat(build, &ch, 1);
        if (ch == ' ')
        {
            junk = atoi(build);
            jiffies[0] += junk;
            if (count < 3)
            {
                jiffies[1] += junk;
            }
            memset(build,0,strlen(build));
            count++;
        }
    }
    fclose(fcpu);
    return jiffies[2];
}
int cpu()
{
    int perc;
    int arr[2] = {0, 0};
    jiff(arr);
    usleep(200000);
    int arr2[2] = {0, 0};
    jiff(arr2);
    perc = (arr[1] - arr2[1]) * 100 / (arr[0] - arr2[0]);
    printf("CPU %d", perc);
    return 0;
}

int main(void)
{
    cpu();
}


