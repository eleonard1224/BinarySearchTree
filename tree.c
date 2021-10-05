// Binary Search Tree Implementation
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void CreateTree(Tree *tree, int value) {
    (*tree)->value = value;
}

void Insert(Tree *tree, int value) {

    if ((*tree) == NULL) {
        Node *node;
        node = calloc(1, sizeof(*node));
        node->value = value;
        *tree = node;
    }
    else {
        if ( value < (*tree)->value ) {
            Insert(&((*tree)->left), value);
        }
        else {
            Insert(&((*tree)->right), value);
        }
    }
}

void PrintTree(Tree tree) {

    if (tree->left != NULL) {
        PrintTree(tree->left);
        if (tree->right != NULL)  {PrintTree(tree->right);}
        printf("Tree Value = %d\n", tree->value);
    }
    else {
        printf("Tree Value = %d\n", tree->value);
    }
}

void FreeTree(Tree tree) {

    if (tree->left != NULL) {
        FreeTree(tree->left);
        if (tree->right != NULL)  {FreeTree(tree->right);}
        free(tree);
    }
    else {
        free(tree);
    }
}

void Find(Position *position, Tree tree, int value) {

    if (tree->value == value) {
        *position = tree;
    }
    if ( (*position)->value != tree->value ) {
        if ( tree->left != NULL ) {
            Find(position, tree->left, value);
        }
        if ( tree->right != NULL ) {
            Find(position, tree->right, value);
        }
    }
}

void Delete(Tree *tree, int value) {}
