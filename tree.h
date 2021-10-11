// Binary Search Tree Declarations
#ifndef TREE
#define TREE

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;
typedef struct Node* Tree;
typedef struct Node* Position;

void CreateTree(Tree *tree, int value);
void Insert(Tree *tree, int value);
void Delete(Tree *tree, int value);
void Find(Position *parent, Position *child, Tree tree, int value);
void FindMin(Position *parent, Position *child, Tree tree);
void PrintTree(Tree tree);
void FreeTree(Tree tree);

#endif