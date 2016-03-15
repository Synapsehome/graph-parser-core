#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "linked_list.h"

int main(int argc, char* argv[]) 
{
    FILE *f;
    uint8_t ret;
    uint32_t buffSize;
    char* pBuff;

    printf("[Read from file file: 'f'] [Generate line: l]\n");

    char option;

READARG:
    scanf("%s", &option);

    switch (option) {
        case 'f': {
                printf("Reading from file\n");
                if ((ret = read_source_graph("out", \
                                &pBuff, &buffSize, &f)) != 0) {
                    printf("Closing\n");
                    return ret;
                }

                struct node *root = NULL;
    
                parse_graph(pBuff, buffSize, &root);
                print_list(root);

                free(pBuff);
                fclose(f);

            }
            break;
        case 'l': {
                printf("Generate line. Please, enter length:\n");
                char length = 0;

                while (!(length > 1)) {
                    scanf("%d", &length);
                    if (!(length > 1))
                        printf("Length too small, chose enter another value\n");
                }

                generate_line(length);
            }
                  break;
        default:
            printf("Error argument\n");
            goto READARG;
            return 2;
    }

    /*if ((ret = read_source_graph("in", &pBuff, &buffSize, &f)) != 0) {
        printf("Closing\n");
        return ret;
    }

    struct node *root = NULL;
    
    parse_graph(pBuff, buffSize, &root);
    print_list(root);

    free(pBuff);
    fclose(f);*/

    return 0;
}
