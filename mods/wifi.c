#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wifi()
{
   FILE *fwifi = fopen("/proc/net/wireless", "r");
   char line[256];
   char s[5];
   int n;
   for (int i = 0; i < 3; i++) 
   {
        fgets(line, sizeof(line), fwifi);
        if (i == 2)
        {
            for (int j = 0; j < strlen(line); j++)
            {
                if (line[j] == '.')
                {
                    sprintf(s, "%c%c%c", line[j - 3], line[j - 2], line[j - 1]);
                    n = atoi(s) * 100 / 70;
                    printf("%d", n);
                    break;
                }
            }
        }
    }
   fclose(fwifi);
}

int main ()
{
    wifi();
}
