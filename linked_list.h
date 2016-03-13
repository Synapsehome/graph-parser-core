#include <stdio.h>
#include <inttypes.h>

struct node {
    uint32_t *vertices;
    uint32_t size;
    uint32_t name;
    struct node *next_node;
};

extern struct node *root;
