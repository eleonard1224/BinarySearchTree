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
        if (tree->right != NULL)  {PrintTree(tree->right);}
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

// Returns a pointer to the node of the tree with value as well as its parent node
void Find(Position *parent, Position *child, Tree tree, int value) {

    // For the root node
    if (tree->value == value) {
        *parent = tree;
        *child = tree;
        return;
    }
    if ( tree->left != NULL && tree->left->value == value ) {
        *parent = tree;
        *child = tree->left;
    }
    else {
        if ( tree->right != NULL && tree->right->value == value ) {
            *parent = tree;
            *child = tree->right;
        }
        else {
            if (value < tree->value) {
                Find(parent, child, tree->left, value);
            }
            else {
                Find(parent, child, tree->right, value);
            }
        }
    }

}

// Returns a pointer to the node of the tree with minimum value as well as its parent node if it exists
void FindMin(Position *parent, Position *child, Tree tree) {

    // If tree does not have a left node
    if ( tree->left == NULL ) {
        *parent = tree;
        *child = tree;
        return;
    }

    while (tree->left->left != NULL) {
        tree = tree->left;
    }
    *parent = tree;
    *child = tree->left;
}

// Deletion of root node doesn't work
void Delete(Tree *tree, int value) {

    // First find node with value
    Position parent, child = NULL;
    Find(&parent, &child, *tree, value);

    // Node has two children
    Position parent_min, child_min = NULL;
    if ( child->left != NULL && child->right != NULL ) {
        FindMin(&parent_min, &child_min, child->right);
        child->value = child_min->value;
        Delete(&(child->right), child_min->value);
    }
    else {
        if (child->left == NULL) {
            if (child->right == NULL) { // Leaf node
                if (parent->left->value == child->value) {
                    parent->left = NULL;
                    free(child);
                }
                else {
                    parent->right = NULL;
                    free(child);
                }
            }
            else { // Node has only right child
                if (parent->left->value == child->value) {
                    parent->left = child->right;
                    free(child);
                }
                else {
                    parent->right = child->right;
                    free(child);
                }
            }

        }
        else { // Node only has left child
            if (parent->left->value == child->value) {
                parent->left = child->left;
                free(child);
            }
            else {
                parent->right = child->left;
                free(child);
            }
        }
    }
}
