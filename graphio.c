#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include "linked_list.h"

uint8_t read_source_graph(char *name, void **out, \
        uint32_t *buffSize, FILE **file)
{
    FILE *f = fopen(name, "r");

    if (f == NULL) {
        printf("[ERROR] Can't open source graph\n");
        return 1;
    }

    size_t size = 0;

    fseek(f, 0, SEEK_END);
    size = ftell(f);
    rewind(f);

    *out = malloc(size + 1);
    memset(*out, 0, size + 1);
    fread(*out, size, 1, f);

    *buffSize = size + 1;
    *file = f;

    return 0;
}

int32_t find_symbol(char* buff, char byte, uint32_t size)
{
    uint32_t i;
    for (i = 0; i < size; i++) {
        if (buff[i] == byte) {
            return i;
        }
    }
    return -1;
}

void parse_current_line(char* buff, uint32_t start, uint32_t end, \
        uint32_t **ppvertices, uint32_t *psize, uint32_t *pname)
{
    uint32_t len = end - start + 1,
             num_spaces = 0;

    char* local_buff = (char*)malloc(len);
    memset(local_buff, 0, len); 
    memcpy(local_buff, &buff[start], len - 1);

    int32_t dash = find_symbol(local_buff, '-', len);

    uint32_t i;
    for (i = 0; i < len; i++) {
        if (local_buff[i] == '\n')
            local_buff[i] = 32;
        if (i > (dash + 2)) {
             if (local_buff[i] == ' ') {
                num_spaces++;
             }
        }
    }
   
    char* name = (char*)malloc(dash + 1);
    memset(name, 0, dash + 1);
    memcpy(name, local_buff, dash - 1);
    uint32_t uname = atoi(name);
    free(name);

    uint32_t *vert_arr = malloc(num_spaces * sizeof(uint32_t)),
             vert_count = 0;

    int32_t s1 = dash + 3, s2 = 0;
    for (i = dash + 4; i < len; i++) {
        if (local_buff[i] == ' ' && s1 == 0) {
            s1 = i;
        }

        if (local_buff[i] == ' ' && s2 == 0) {
            s2 = i;
        }

        if (s1 != 0 && s2 != 0) {
            char* vbuff = malloc(s2 - s1 + 1);
            memset(vbuff, 0, s2 - s1 + 1);
            memcpy(vbuff, &local_buff[s1], s2 - s1 + 1);
            vert_arr[vert_count] = (uint32_t)atoi(vbuff);
            vert_count++;
            free(vbuff);

            s1 = s2;
            s2 = 0;
        }
    }

    //get last vertex form the end
    for (i = len - 1; i > 0; i--) {
        if (local_buff[i] == ' ') {
            char* vbuff = malloc(len - i + 1);
            memset(vbuff, 0, len - i + 1);
            memcpy(vbuff, &local_buff[s1], len - i);
            vert_arr[vert_count] = (uint32_t)atoi(vbuff);
            vert_count++;
            free(vbuff);
            break;
        }
    }
    
    if (pname != NULL)
        *pname = uname;
    if (psize != NULL)
        *psize = vert_count;
    if (ppvertices != NULL)
        *ppvertices = vert_arr;
    
    free(local_buff);
    return;
}

void parse_graph(char* buff, uint32_t size, \
                 struct node **root, uint32_t *vertcount)
{
    uint32_t start = 0,
             end = 0,
             i = 0,
             vertex_count = 0;

    struct node *tmp_root = NULL;

    for (i = 0; i < size; i++) {
        if (buff[i] == '\n') {
            start = end;
            end = i;

            if ((end - start) <= 2)
                continue;
            
            struct node nd;
            init_empty_node(&nd);

            parse_current_line(buff, (start == 0) ? start : start + 1, end, \
                    &nd.vertices, &nd.size, &nd.name);

            push_back(&tmp_root, nd);
            vertex_count++;
        }  
    }

    *root = tmp_root;
    *vertcount = vertex_count;
}

uint32_t read_length(uint32_t min) 
{
    unsigned int length = 0;
    
    while (!(length > min)) {
        scanf("%d", &length);
        if (!(length > min))
            printf("Too small value, chose another\n");
    }
    return length;
}

