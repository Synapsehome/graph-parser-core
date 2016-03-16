#include "matrix.h"
#include "linked_list.h"

uint32_t get_elem(struct matrix_t *mx, uint32_t i, uint32_t j)
{
    if (mx == NULL)
        return -1;

    return mx->elems[mx->size*(i - 1) + (j - 1)];
}

void set_elem(struct matrix_t *mx, uint32_t i, uint32_t j, uint32_t val)
{
    if (mx == NULL)
        return;

    mx->elems[mx->size*(i - 1) + (j - 1)] = val;
}

void init_matrix(struct matrix_t *mx, uint32_t sz)
{
    if (mx == NULL)
        return;

    mx->size = sz;
    mx->elems = calloc(sz * sz, sizeof(uint32_t));
}

uint32_t find_value(uint32_t *p, uint32_t size, uint32_t val)
{
    uint32_t i;
    for (i = 0; i < size; i++) {
        if (p[i] == val)
            return 1;
    }

    return 0;
}

uint32_t find_path_between_vertices(struct node *root, \
                                    uint32_t vert1, uint32_t vert2)
{
    struct node *p = root;
    
    while (p->name != vert1) {
        if (p->next_node != NULL) {
            p = p->next_node;
        }
    }

    if (p->name == vert1)
        return find_value(p->vertices, p->size, vert2);
    else
        return 0;
}

void print_matrix(struct matrix_t *mx)
{
    uint32_t i, j;
    for (i = 1; i <= mx->size; i++) {
        for (j = 1; j <= mx->size; j++) {
            printf("%d ", get_elem(&(*mx), i, j));
        }
        printf("\n");
    }

}

uint32_t get_vertex_size_by_name(uint32_t name, struct node* root)
{
    if (root == NULL)
        return 0;

    struct node *p = root;
    for (;;) {
        if (p->name == name)
            return p->size;
        
        if (p->next_node != NULL)
            p = p->next_node;
        else
            return 0;
    }
    return 0;
}
