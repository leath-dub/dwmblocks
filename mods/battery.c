#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void battery() 
{
    FILE *fbat;
    int n;
    int perc;
    char bat_arr[5][14] = {"","","","",""};
    fbat = fopen(
       "/sys/class/power_supply/BAT0/capacity", "r"
    );
    fscanf(fbat, "%d", &n);
    perc = n;
    n = n / 21;
    printf("%s %d", bat_arr[n], perc);
    fclose(fbat);
}
int main(void)
{
    battery();
}
