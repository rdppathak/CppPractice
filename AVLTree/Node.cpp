#include "Node.h"

void pre_order_traversal(struct Node *root){
    if (root == NULL){
        return;
    }
    printf("%d ", root->data);
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

int max(int a, int b){
    return (a>b)? a : b;
}

int get_balance(struct Node *n){
    if (n==NULL){
        return 0;
    }
    return (height(n->left)-height(n->right));
}

int height(struct Node *n){
    if (n==NULL){
        return 0;
    }
    return n->height;
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

struct Node* right_rotate(struct Node *node){
    struct Node *x = node->left;
    struct Node *T2 = x->right;

    x->right = node;
    node->left = T2;

    node->height = max(height(node->left), height(node->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}

struct Node* left_rotate(struct Node *node){
    struct Node *y = node->right;
    struct Node *T2 = y->left;

    y->left = node;
    node->right = T2;

    y->height = max(height(y->left), height(y->right))+1;
    node->height = max(height(node->left), height(node->right))+1;

    return y;
}

struct Node *insert(struct Node *n, int data){
    if(n==NULL){
        printf ("Inserting element[%d]\n", data);
        return create_node(data);
    }
    if(n->data >data){
        n->left = insert(n->left, data);
    }else{
        n->right = insert(n->right, data);
    }

    n->height = max(height(n->left), height(n->right)) +1;

    int balance = get_balance(n);

    //Left Left case
    if ((balance > 1) && (data < n->left->data)){
        return right_rotate(n);
    }

    //left right case
    if (balance > 1 && (data > n->left->data)){
        n->left = left_rotate(n->left);
        return right_rotate(n);
    }

    //right right case
    if ((balance < -1) && (data>n->right->data)){
        return left_rotate(n);
    }

    //right left case
    if ((balance < -1) && (data <n->right->data)){
        n->right = right_rotate(n->right);
        return left_rotate(n);
    }
    return n;
}
