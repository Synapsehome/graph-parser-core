#include "linked_list.h"

struct node *root = NULL;

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
