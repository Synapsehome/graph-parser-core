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
    

    printf("Readed %u bytes\n", buffSize);

    parse_graph(pBuff, buffSize);
    
    /*uint32_t i;
    for(i = 0; i < buffSize; i++) {
        if(pBuff[i] == '\n') {
            printf("T");
        }
    }
    */

    /*
    root = NULL;

    struct node tmp;
    init_empty_node(&tmp);
    
    tmp.name = 1;
    tmp.size = 11;
    push_back(&root, tmp);

    tmp.name = 2;
    tmp.size = 22;
    push_back(&root, tmp);

    tmp.name = 3;
    tmp.size = 33;
    push_back(&root, tmp);

    print_list(root);*/

    return 0;
}
