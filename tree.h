#ifndef TREE_H
#define TREE_H

void add_node(unsigned int k);
void rightmost_child(unsigned int k);
void delete_node(unsigned int k);
void delete_subtree(unsigned int k);
void split_node(unsigned int k, unsigned int w);
int nodes_num();
void initiate();
void clear();

#endif /* TREE_H */