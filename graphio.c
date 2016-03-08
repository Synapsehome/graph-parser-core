#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

FILE *pSrc = NULL;
char *pBuff = NULL;

uint8_t
read_source_graph(char* name, void* out)
{
    pSrc = fopen(name, "r");
    
    if (pSrc == NULL) {
        printf("[ERROR] Can't open source graph\n");
        return 1;
    } else {
        printf("Opening OK\n");
    }

    size_t size = 0;

    fseek(pSrc, 0, SEEK_END);
    size = ftell(pSrc);

    //printf("size: %i\n", size);

    rewind(pSrc); //begin of the file

    pBuff = malloc(size + 1);
    fread(pBuff, size, 1, pSrc); 
    pBuff[size] = '\0';
    fclose(pSrc);

    printf("%s\n", pBuff);
    printf("!"); 

    free(pBuff);
    return 0;
}
