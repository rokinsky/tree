#include <stdlib.h>
#include "list.h"

Node* create_list() {
    Node *l = (Node*) malloc(sizeof(Node));

    l->next = l;
    l->prev = l;

    return l;
}

void pop_node_right(Node *k, Node *n) {
    n->next = k->children;
    n->prev = k->children->prev;
    k->children->prev->next = n;
    k->children->prev = n;
    n->children = NULL;
}

void split_list(Node *w, Node *n) {
    n->children = create_list();
    n->children->next = w->next;
    n->children->prev = n->prev;
    w->next->prev = n->children;
    n->prev->next = n->children;
    w->next = n;
    n->prev = w;
}

void brothers_to_brothers(Node *n, Node *m) {
    n->prev->next = m->next;
    n->next->prev = m->prev;
}

status is_empty_list(const Node *l) {
    if (l != NULL) {
        return l == l->prev ? EMPTY : NONEMPTY;
    }
    else {
        return NONEXISTENT;
    }
}

void remove_empty_list(Node *l) {
    free(l);
}