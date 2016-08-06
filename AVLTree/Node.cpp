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

struct Node* get_minimum_value_node(struct Node* root){
    struct Node* current = root;
    while(current->left!=NULL){
        current = current->left;
    }

    return current;
}

struct Node* delete_node(struct Node* root, int key){
    if (root == NULL){
        return root;
    }

    if(root->data < key){
        //Element belongs in right subtree
        root->right = delete_node(root->right, key);
    }else if(root->data > key){
        //Element belongs in left subtree
        root->left = delete_node(root->left, key);
    }else{
        //Element found
        struct Node* temp = NULL;
        if (root->left == NULL || root->right == NULL){
            if(root->left == NULL){
                temp = root->right;
            }else{
                temp = root->left;
            }

            if (temp == NULL){
                temp = root;
                root = NULL;
            }else{
                *root = *temp;
            }
            free(temp);
        }else{
            struct Node* temp;
            temp = get_minimum_value_node(root->right);

            root->data = temp->data;

            root->right = delete_node(root->right, temp->data);
        }

    }
    if(root == NULL){
        return root;
    }

    //Update the height 

    root->height = max(height(root->left), height(root->right))+1;

    int balance = get_balance(root);

    if (balance>1 && get_balance(root->left)>=0){
        right_rotate(root);
    }

    if (balance>1 && get_balance(root->left)<0){
        root->left = left_rotate(root->left);
        right_rotate(root);
    }

    if (balance<-1 && get_balance(root->right)<=0){
        left_rotate(root);
    }

    if (balance<-1 && get_balance(root->right)>0){
        root->right = right_rotate(root->right);
        left_rotate(root);
    }
    return root;
}