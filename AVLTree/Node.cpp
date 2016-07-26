#include "Node.h"

int max(int a, int b){
    return (a>b)? a : b;
}

int get_balance(struct Node *n){
    if (n==NULL){
        return 0;
    }
    return (height(n->left)-height(n->right));
}

struct Node* create_node(int data){
    struct Node *new_node;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}

struct Node *insert(struct Node *n, int data){
    if(n==NULL){
        return create_node(data);
    }
    if(n->data >data){
        n-left = insert(n->left, data);
    }else{
        return insert(n->right, data);
    }

    node->height = max(height(node->left), height(node->right)) +1;

    int balance = get_balance(node);
}
