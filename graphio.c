#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

FILE *pSrc = NULL;
char *pBuff = NULL;

uint8_t
read_source_graph(char* name, void* out, uint32_t *buffSize)
{
    pSrc = fopen(name, "r");
    
    if (pSrc == NULL) {
        printf("[ERROR] Can't open source graph\n");
        return 1;
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

    //printf("%s\n", pBuff);

    *buffSize = size + 1; 

    free(pBuff);
    return 0;
}

int32_t
find_symbol(char* buff, char byte, uint32_t size)
{
    uint32_t i;
    for(i = 0; i < size; i++) {
        if (buff[i] == byte) {
            return i;
        }
    }
    return -1;
}

void
parse_current_line(char* buff, uint32_t start, uint32_t end)
{
    uint32_t len = end - start + 1;
    char* local_buff = (char*)malloc(len);
    memset(local_buff, 0, len);
    
    memcpy(local_buff, &buff[start], len - 1);

    uint32_t i;
    for (i = 0; i < len; i++) {
        if (local_buff[i] == '\n')
            local_buff[i] = 32;
    }

    printf("%s\n", local_buff);

    //find first '-' symbol
    
    int32_t dash = find_symbol(local_buff, '-', len);
    
    char* name = (char*)malloc(dash + 1);
    memset(name, 0, dash + 1);

    memcpy(name, local_buff, dash - 1);
    uint32_t uname = atoi(name);

    printf("name %d\n", uname);

    free(local_buff);
    return;
}

void
parse_graph(char* buff, uint32_t size)
{
    uint32_t start = 0,
             end = 0,
             i = 0;

    for (i = 0; i < size; i++) {
        if (buff[i] == '\n') {
            start = end;
            end = i;

            //printf("before parse: %d %d", start, end);

            if ((end - start) <= 2)
                continue;

            parse_current_line(buff, (start == 0) ? start : start + 1, end);
            //break;
        }  
    }
}
