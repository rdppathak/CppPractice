#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int, int);
int get_balance(struct Node*);
int height(struct Node*);
struct Node* create_node(int);
struct Node *insert(struct Node*, int);
struct Node* get_minimum_value_node(struct Node*);
struct Node* delete_node(struct Node*, int);
void pre_order_traversal(struct Node*);
