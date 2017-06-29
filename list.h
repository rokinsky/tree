#ifndef LIST_H
#define LIST_H

typedef enum {
    EMPTY,
    NONEMPTY,
    NONEXISTENT
} status;

typedef struct Node {
    unsigned int num;
    struct Node *children;
    struct Node *next;
    struct Node *prev;
} Node;

Node* create_list();
void pop_node_right(Node *k, Node *n);
void brothers_to_brothers(Node *n, Node *m);
void split_list(Node *k, Node *n);
status is_empty_list(const Node *l);
void remove_empty_list(Node *l);

#endif /* LIST_H */