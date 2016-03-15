#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

void generate_line(uint32_t len)
{
    FILE *f;
    f = fopen ("out", "w+");

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

void generate_circle(uint32_t len) 
{
    FILE *f;
    f = fopen ("out", "w+");

    uint32_t i;
    for (i = 1; i <= len; i++) {
        if (i == 1) {               /*First vertex*/
            fprintf(f, "1 --> 2 %d\n", len);
        } else if (i == len) {      /*Last vertex*/
            fprintf(f, "%d --> %d 1\n", len, len - 1);
        } else {
            fprintf(f, "%d --> %d %d\n", i, i - 1, i + 1);
        }

        if (i != len)
            fprintf(f, "\n");
    }

    fclose(f);
}

void generate_star(uint32_t len)
{
    FILE *f;
    uint32_t i;
    f = fopen ("out", "w+");
    /*First line*/
    fprintf(f, "1 -->");
    for (i = 2; i <= len; i++)
        fprintf(f, " %d", i);
    fprintf(f, "\n");
    
    for (i = 2; i <= len; i++) {
        fprintf(f, "%d --> 1", i);

        if (i != len)
            fprintf(f, "\n");
    }

    fclose(f);
}

void generate_complete(uint32_t len)
{
    FILE *f;
    uint32_t i;
    f = fopen ("out", "w+");
    
    for (i = 1; i <= len; i++) {
        fprintf(f, "%d -->", i);
        
        uint32_t j;
        for (j = 1; j <= len; j++) {
            if (j != i) {
                fprintf(f, " %d", j);
            }
        }

        fprintf(f, "\n");
        
        if (i != len)    
            fprintf(f, "\n");
    }

    fclose(f);
}
