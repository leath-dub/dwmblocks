#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void battery() 
{
    FILE *fbat = fopen("/sys/class/power_supply/BAT0/capacity", "r");
    FILE *fac = fopen("/sys/class/power_supply/AC/uevent", "r");
    int perc;
    int isAC;
    char line[256];
    char bat_charging[8][14] = {"", "", "", "", "", "", "", ""};
    char bat_discharging[11][14] = {"", "", "", "", "", "", "", "", "", "", ""};
    fscanf(fbat, "%d", &perc);
    for (int i = 0; i < 3; i++)
    {
        fscanf(fac, "%s", &line);
    }
    isAC = line[strlen(line) - 1];
    if (isAC == '1')
    {
        printf("%s %d", bat_charging[perc / 13], perc);
    }
    else
    {
        printf("%s %d", bat_discharging[perc / 10], perc);
    }
    fclose(fbat);
    fclose(fac);
}
int main(void)
{
    battery();
    return 0;
}
