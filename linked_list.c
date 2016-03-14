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
    if (*root == NULL) {
        struct node* p = (struct node*)malloc(sizeof(struct node));
        init_empty_node(p);
        fill_node(p, data);
        *root = p;
        return;
    }

    if ((*root)->next_node == NULL) {
        struct node* next = insert_node(*root);
        fill_node(next, data);
        return;
    } else {
        struct node *p = *root;
        while (p->next_node != NULL) {
            p = p->next_node;
            if (p->next_node == NULL) {
                struct node *next = insert_node(p);
                fill_node(next, data);
                return;
            }
        }
    }
}

void
print_list(struct node* root)
{
    struct node *p = root;

    while (p != NULL) {
        printf("Size: %d Name %d\n", p->size, p->name);
        p = p->next_node;
    }
}
