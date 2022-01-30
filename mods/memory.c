#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "/home/cathal/.dev/c-programs/config.h"

int memory()
{
    FILE *fmem = fopen("/proc/meminfo", "r");
    char ch;
    char rg[11] ={'0','1','2','3','4','5','6','7','8','9','\0'};
    char MemTot_CH[20] = "";
    char MemAv_CH[20] = "";
    int MemTot;
    int MemAv;
    if (fmem == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        int count = 0;
        while (((ch = fgetc(fmem)) != EOF) && (count != 3))
        {
            int i = 0;
            while (rg[i] != '\0')
            {
                if ((ch == rg[i]) && (count != 1))
                {
                    if (count == 0)
                    {
                        strncat(MemTot_CH, &ch, 1);
                    }
                    else
                    {
                        strncat(MemAv_CH, &ch, 1);
                    }
                }
                i++;
            }
            if (ch == '\n')
            {
                count++;
            }
        }
    }
    sscanf(MemTot_CH, "%d", &MemTot);
    sscanf(MemAv_CH, "%d", &MemAv);
    int used = (MemTot - MemAv) / 1000;
    MemTot = MemTot / 1000;
    int perc = (used * 100/ MemTot * 100) / 100;
    if (memperc == 1)
    {
        printf(" %d", perc);
    }
    else
    {
        printf(" %dMb / %dMb", used, MemTot);
    }
    fclose(fmem);
    return 0;
}
int main(void)
{
    memory();
}
