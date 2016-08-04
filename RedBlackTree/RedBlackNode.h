#include <stdio.h>
#include <string.h>

enum Color {RED, BLACK};

struct RedBlackNode{
    int data;
    struct RedBlackNode *left, *right, *parent;
    bool color;
};
