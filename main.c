// Binary Search Tree Main File
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"


int main() {

    Tree tree = NULL;
    tree = calloc(1, sizeof(*tree));
    CreateTree(&tree, 6);
    Insert(&tree, 2);
    Insert(&tree, 8);
    Insert(&tree, 1);
    Insert(&tree, 4);
    Insert(&tree, 3);

    printf("Binary Search Tree\n");
    PrintTree(tree);

    Position position = NULL;
    position = calloc(1, sizeof(*position));
    Find(&position, tree, 2);
    printf("Find: position->value = %d\n", position->value);

    FreeTree(tree);
    return 0;
}