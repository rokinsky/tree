/**
 * "Drzewo"
 *
 * autor: Aliaksandr Sarokin <as372525@mimuw.edu.pl>
 * wersja: 1.0
 * data: 30 marca 2017
**/

#include "tree.h"
#include "parse.h"

#define FOREVER while (1)

int main(int argc, char **args) {
    unsigned int k, w;

    if (!check_args(argc, args)) {
        error();
        return 1;
    }
    
    initiate();

    do {
        switch(get_command(&k, &w)) {
            case ADD_NODE:
                add_node(k);
                break;
            case RIGHTMOST_CHILD:
                rightmost_child(k);
                break;
            case DELETE_SUBTREE:
                delete_subtree(k);
                break;
            case DELETE_NODE:
                delete_node(k);
                break;
            case SPLIT_NODE:
                split_node(k, w);
                break;
            case UNDEFINED:
                error();
                break;
            case EXIT:
                clear();
                return 0;
        }

        debug();

    } FOREVER;
}