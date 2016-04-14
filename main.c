#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "linked_list.h"
#include "matrix.h"

int
main(int argc, char* argv[]) 
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
                struct node *root = NULL;
                uint32_t vertex_count = 0;
                
                printf("Reading from file\n");
                if ((ret = read_source_graph("out", \
                                &pBuff, &buffSize, &f)) != 0) {
                    printf("Closing\n");
                    return ret;
                }

                parse_graph(pBuff, buffSize, &root, &vertex_count);
                printf("[BUG IN STAR. LOST LAST VERTEX]%d vertices detected\n", \
                       vertex_count);

                print_list(root);

                struct matrix_t mx;
                init_matrix(&mx, vertex_count);
                
                uint32_t i, j;
                for (i = 1; i <= vertex_count; i++) {
                    for (j = 1; j <= vertex_count; j++) {
                        if (i != j) {
                            set_elem(&mx, i, j, \
                                     find_path_between_vertices(root, i, j));
                        } else {
                            /*Diagonal elements*/
                            set_elem(&mx, i, j, \
                                     get_vertex_size_by_name(i, root) + 1);
                        }
                    }
                }

                print_matrix(&mx);
                free(mx.elems);

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
