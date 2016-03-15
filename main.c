#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "linked_list.h"

int
main(int argc, char* argv[]) 
{
    FILE *f;
    uint8_t ret;
    char* pBuff;
    uint32_t buffSize;

    if ((ret = read_source_graph("in", &pBuff, &buffSize, &f)) != 0) {
        printf("Closing\n");
        return ret;
    }

    struct node *root = NULL;
    
    parse_graph(pBuff, buffSize, &root);
    print_list(root);

    free(pBuff);
    fclose(f);

    return 0;
}
