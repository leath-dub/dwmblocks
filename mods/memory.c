#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

void memory()
{
    FILE *fmem = fopen("/proc/meminfo", "r");
    char line[256];
    int MemTot;
    int MemAv;
    for (int i = 0; i < 8; i++)
    {
        fscanf(fmem, "%s", &line);
        switch(i)
        {
            case 1:
                MemTot = atoi(line);
                break;
            case 7:
                MemAv = atoi(line);
        }
    }
    switch(memperc)
    {
        case 0:
            printf(" %dMb / %dMb", (MemTot - MemAv) / 1000, MemTot / 1000);
            break;
        case 1:
            printf(" %d", (MemTot - MemAv) * 100/ MemTot);
    }
    fclose(fmem);
}
void main(void)
{
    memory();
}
