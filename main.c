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

    //printf("%s\n", pBuff);

    //FILE *f = fopen("in", "r");

    /*if (f != NULL) {
        fclose(f);
    }*/


    //free(pBuff);
    

    //printf("Readed %u bytes\n", buffSize);

    //root = NULL;
    //
    struct node *root = NULL;
    
    parse_graph(pBuff, buffSize, &root);
    
    /*uint32_t i;
    for(i = 0; i < buffSize; i++) {
        if(pBuff[i] == '\n') {
            printf("T");
        }
    }
    */

    
    /*struct node *root = NULL;

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

    tmp.name = 4;
    tmp.size = 44;
    push_back(&root, tmp);

    tmp.name = 5;
    tmp.size = 55;
    push_back(&root, tmp);*/


    print_list(root);

    free(pBuff);
    fclose(f);

    return 0;
}
