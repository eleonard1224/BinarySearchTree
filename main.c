// Binary Search Tree Main File
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

// ----------------------------------------- Example in main ---------------------------------------------
//          Initial Tree                                Tree After Deletion of Node with Value 2
//               6                                                        6
//              / \                                                      / \
//             2   8                                                    3   8
//            / \                                                      / \
//           1   5                                                    1   5
//              /                                                        / 
//             3                                                        4
//              \
//               4
// -------------------------------------------------------------------------------------------------------


int main() {

    Tree tree = NULL;
    tree = calloc(1, sizeof(*tree));
    CreateTree(&tree, 6);
    Insert(&tree, 2);
    Insert(&tree, 8);
    Insert(&tree, 1);
    Insert(&tree, 5);
    Insert(&tree, 3);
    Insert(&tree, 4);
    printf("Binary Search Tree\n");
    PrintTree(tree);

    printf("------------------------\n");

    printf("Binary Search Tree After Deletion of Node With Value 2\n");
    Delete(&tree, 2);
    PrintTree(tree);

    FreeTree(tree);
    return 0;
}