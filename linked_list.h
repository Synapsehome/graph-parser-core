#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

struct node {
    uint32_t *vertices;
    uint32_t size;
    uint32_t name;
    struct node *next_node;
};
