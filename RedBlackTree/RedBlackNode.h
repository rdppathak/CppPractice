#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Color {RED, BLACK};

struct RedBlackNode{
    int data;
    struct RedBlackNode *left, *right, *parent;
    bool color;
};

struct RedBlackNode* create_node(int);
struct RedBlackNode* bst_insert(struct RedBlackNode*, struct RedBlackNode*);
void display_inorder(struct RedBlackNode*);

void rotate_right(struct RedBlackNode *&, struct RedBlackNode *&);
void rotate_left(struct RedBlackNode *&, struct RedBlackNode *&);
void check_voilations(struct RedBlackNode*&, struct RedBlackNode*&);
struct RedBlackNode* insert(struct RedBlackNode*, int data);
