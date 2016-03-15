#include "linked_list.h"

void
init_empty_node(struct node *p)
{
    return;
    if (p != NULL) { 
        p->size = 0;
        p->name = 0;
        p->vertices = NULL;
        p->next_node = NULL;
    }
}

struct node* 
insert_node(struct node *p)
{
    if (p == NULL)
        return NULL;

    if (p->next_node == NULL) {
        p->next_node = (struct node*)malloc(sizeof(struct node));
        init_empty_node(p->next_node);
        return p->next_node;
    }
}

void
fill_node(struct node *p, struct node data)
{
    p->name = data.name;
    p->size = data.size;
    p->vertices = data.vertices;
}

void
push_back(struct node **root, struct node data)
{
    struct node *p = *root;

    if (p == NULL) {
        struct node* p = (struct node*)malloc(sizeof(struct node));
        init_empty_node(p);
        fill_node(p, data);
        *root = p;
        return;
    }

    for (;;) {
        if (p->next_node != NULL) {
            p = p->next_node;
        } else {
            p->next_node = malloc(sizeof(struct node));
            init_empty_node(p->next_node);
            fill_node(p->next_node, data);
            return;
        }
    }
}

void
print_list(struct node* root)
{
    struct node *p = root;
    uint32_t t = 0;

    while (p != NULL) {
        printf("[Name: %d Size: %d Vertices:", p->name, p->size);
        
        uint32_t i;
        for (i = 0; i < p->size; i++) {
            printf(" %d", p->vertices[i]);
        }
        printf("]\n");

        p = p->next_node;
    }
}
