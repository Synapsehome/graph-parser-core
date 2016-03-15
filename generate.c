#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

void generate_line(uint32_t len)
{
    FILE *f;
    f = fopen ("out", "w+");
    //fprintf(fp, "%s %s %s %d", "We", "are", "in", 2012);
   
    uint32_t i;
    for (i = 1; i <= len; i++) {
        if (i == 1) {               /*First vertex*/
            fprintf(f, "1 --> 2\n");
        } else if (i == len) {      /*Last vertex*/
            fprintf(f, "%d --> %d\n", len, len - 1);
        } else {
            fprintf(f, "%d --> %d %d\n", i, i - 1, i + 1);
        }

        if (i != len)
            fprintf(f, "\n");
    }
    fclose(f);
}
