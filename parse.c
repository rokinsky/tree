#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "parse.h"

#define MAX_LENGTH_INPUT_COMMAND 32

static char s[MAX_LENGTH_INPUT_COMMAND];
static bool dbgflag;

void error(void) {
    printf("ERROR\n");
}

bool check_args(int argc, char **args) {
    if ((argc > 2) || (argc == 2 && strcmp(args[1],"-v") != 0)) {
        return false;
    } 
    else {
        dbgflag = (argc == 2);
        return true;
    }
}

void debug(void) {
    if (dbgflag == true) {
        fprintf(stderr, "NODES: %d\n", nodes_num());
    }
}

command get_command(unsigned int *k, unsigned int *w) {
    if  (scanf("%s", s) == EOF || strcmp(s, "EXIT") == 0) {
        return EXIT;
    }
    else if (strcmp(s, "ADD_NODE") == 0) {
        if (scanf("%u", k) == 1) {
            return ADD_NODE;
        }
    }
    else if (strcmp(s, "RIGHTMOST_CHILD") == 0) {
       	if (scanf("%u", k) == 1) {
            return RIGHTMOST_CHILD;
        }
    }
    else if (strcmp(s, "DELETE_NODE") == 0) {
        if (scanf("%u", k) == 1) {
            return DELETE_NODE;
        }
    }
    else if (strcmp(s, "DELETE_SUBTREE") == 0) {
        if (scanf("%u", k) == 1) {
            return DELETE_SUBTREE;
        }
    }
    else if (strcmp(s, "SPLIT_NODE") == 0) {
        if (scanf("%u %u", k, w) == 2) {
            return SPLIT_NODE;
        }
    }
    return UNDEFINED;
}