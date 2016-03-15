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
    //printf("pb called\n");
    //if (data.name == 4) {
   //     printf("pb called\n");
   // }
    struct node *p = *root;
    if (p == NULL) {
        //printf("here!!");
        struct node* p = (struct node*)malloc(sizeof(struct node));
        init_empty_node(p);
        fill_node(p, data);
        *root = p;
        return;
    }

    //printf("HERE!\n");
    //
    //
    for (;;) {
        if (p->next_node != NULL) {
            //printf("name: %d next_node 0x%x\n", p->name, p->next_node);
            p = p->next_node;
        } else {
            p->next_node = malloc(sizeof(struct node));
            init_empty_node(p->next_node);
            fill_node(p->next_node, data);
            return;
        }
    }
    
    /*if (p->next_node == NULL) {
        //struct node* next = insert_node(p);
        p->next_node = malloc(sizeof(struct node));
        fill_node(p->next_node, data);
        //printf("Next rott filled\n");
        return;
    } else {
        p = p-> next_node;
        return;
        //printf("2\n");
        struct node *p = *root;
        while (1) {
            //p = p->next_node;
            printf("Here\n");
            if (p->next_node == NULL) {
                printf("lala1\n");
                struct node *next = insert_node(p);
                printf("lala2l\n");
                fill_node(next, data);
                return;
            }
            if (p->next_node != NULL)
                p = p->next_node;
        }
    }*/

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
