#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "list.h"

#define MAX_N 454547 /* maksymalna liczba wieszcholkow dla plika 5MB */

static size_t elements;
static unsigned int last_num;
static Node tree[MAX_N];

int nodes_num() {
    return elements;
}

static void message() {
    printf("OK\n");
}

static void add_node_support(unsigned int k) {
    if (is_empty_list(tree[k].children) == NONEXISTENT) {
        tree[k].children = create_list();
    }
    last_num++;
    tree[last_num].num = last_num;
    pop_node_right(&(tree)[k], &(tree)[last_num]);
    elements++;
}

void add_node(unsigned int k) {
    add_node_support(k);
    message();
}

void rightmost_child(unsigned int k) {
    if (is_empty_list(tree[k].children) == NONEMPTY) {
        printf("%d\n", tree[k].children->prev->num);
    }
    else {
        printf("%d\n", -1);
    }
}

static void delete_node_support(unsigned int k) {
    switch (is_empty_list(tree[k].children)) {
        case NONEMPTY: 
            brothers_to_brothers(&(tree)[k], tree[k].children);
            brothers_to_brothers(tree[k].children, &(tree)[k]);
            remove_empty_list(tree[k].children);
            break;
       	case EMPTY:
            brothers_to_brothers(&(tree)[k], &(tree)[k]);
            remove_empty_list(tree[k].children);
            break;
        case NONEXISTENT:
            brothers_to_brothers(&(tree)[k], &(tree)[k]);
            break;
    }
    elements--;
}

void delete_node(unsigned int k) {
    delete_node_support(k);
    message();
}

static void delete_subtree_support(unsigned int k) {
    while (is_empty_list(tree[k].children) == NONEMPTY) {
        delete_subtree_support(tree[k].children->next->num);
    }
    delete_node_support(k);
}

void delete_subtree(unsigned int k) {
    delete_subtree_support(k);
    message();
}

void split_node(unsigned int k, unsigned int w) {
    add_node_support(k);
    if (tree[w].next != &(tree[last_num])) {
        split_list(&(tree)[w], &(tree)[last_num]);
    }
    message();
}

void initiate() {
    elements = 1;
    tree[0].num = last_num = 0;
    tree[0].children = create_list();
    tree[0].next = tree[0].prev = NULL;
}

void clear() {
    while (is_empty_list(tree[0].children) == NONEMPTY) {
        delete_subtree_support(tree[0].children->next->num);
    }
    remove_empty_list(tree[0].children);
}