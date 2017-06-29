#ifndef PARSE_H
#define PARSE_H

#include <stdbool.h>

typedef enum {
    ADD_NODE,
    RIGHTMOST_CHILD,
    DELETE_NODE,
    DELETE_SUBTREE,
    SPLIT_NODE,
    EXIT,
    UNDEFINED
} command;

command get_command(unsigned int *k, unsigned int *w);
bool check_args(int argc, char **args);
void debug(void);
void error(void);

#endif /* PARSE_H */