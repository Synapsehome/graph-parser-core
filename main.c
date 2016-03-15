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
    printf("[Generate complete graph: 'c']\n");
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
                unsigned char length;
                //read_length(&length, 1);

                while (!(length > 1)) {
                    scanf("%d", &length);
                    if (!(length > 1))
                        printf("Length too small, chose enter another value\n");
                } 

                generate_line(length);
            }
            break;
        case 'r': {
                printf("Generate ring. Please, enter length:\n");
                unsigned char length = 0;

                while (!(length > 2)) {
                    scanf("%d", &length);
                    if (!(length > 2))
                        printf("Length too small, chose enter another value\n");
                }

                generate_circle(length);
            }
            break;
        case 's': {
                printf("Generate star. Please, enter length:\n");
                unsigned char length = 0;

                while (!(length > 2)) {
                    scanf("%d", &length);
                    if (!(length > 2))
                        printf("Length too small, chose enter another value\n");
                }

                generate_star(length);
        }
            break;
        case 'c': {
                printf("Complete graph. Please, enter length:\n");
                unsigned char length = 0;

                while (!(length > 2)) {
                    scanf("%d", &length);
                    if (!(length > 2))
                        printf("Length too small, chose enter another value\n");
                }

                generate_complete(length);
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
