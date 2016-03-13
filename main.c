#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "linked_list.h"

//source graph
extern char *pBuff; 

int
main(int argc, char* argv[]) 
{
    uint8_t ret;
    uint32_t buffSize;

    if ((ret = read_source_graph("in", pBuff, &buffSize)) != 0) {
        printf("Closing\n");
        return ret;
    }
    
    root = (struct node*)malloc(sizeof(struct node));
    init_empty_node(root);

    uint32_t i;
    for(i = 0; i < buffSize; i++) {
        if(pBuff[i] == '\n') {
            printf("T");
        }
    }


    return 0;
}
