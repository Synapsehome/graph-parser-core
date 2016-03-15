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

    printf("[Read from file file: 'f']\n[Generate line: 'l']\n");
    printf("[Generate ring: 'r']\n");
    printf("[Generate star: 's']\n");
    printf("[Generate complete graph: 'c']\n[Generate dandelion: 'd']\n");
    printf("[Exit: 'q']\n");

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
                erase_list(root);

                free(pBuff);
                fclose(f);
            }
            break;
        case 'l': {
                printf("Generate line. Please, enter length:\n");
                generate_line(read_length(1));
            }
            break;
        case 'r': {
                printf("Generate ring. Please, enter length:\n");
                generate_circle(read_length(2));
            }
            break;
        case 's': {
                printf("Generate star. Please, enter length:\n");
                generate_star(read_length(2));
        }
            break;
        case 'c': {
                printf("Complete graph. Please, enter length:\n");
                generate_complete(read_length(2));
            }
            break;
        case 'd': {
                printf("Generate dandelion. Please, enter size:\n");
                generate_dandelion(read_length(2));
            }
            break;
        case 'q' : {
                return 0;
            }
            break;
        default:
            printf("Error argument\n");
            goto READARG;
            return 2;
    }

    return 0;
}
