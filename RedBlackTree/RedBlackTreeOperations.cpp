#include "RedBlackNode.h"


struct RedBlackNode* create_node(int data){
        struct RedBlackNode *new_node;
        new_node = (struct RedBlackNode*)malloc(sizeof(struct RedBlackNode));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->parent = NULL;
        new_node->color = RED;

        return new_node;
}

struct RedBlackNode* bst_insert(struct RedBlackNode* root, struct RedBlackNode* new_node)
{
    if (root==NULL){
        printf("Creating new node with data[%d]\n", new_node->data);
        return new_node;
    }

    if(root->data > new_node->data){
        //Insert node in left half of tree
        root->left = bst_insert(root->left, new_node);
        root->left->parent = root;
    }else{
        //Insert node in right half of tree
        root->right = bst_insert(root->right, new_node);
        root->right->parent = root;
    }
    return root;
}

void display_inorder(struct RedBlackNode* root){
    if(root != NULL){
        display_inorder(root->left);
        printf("{Data[%d],Color[%d],",
            root->data, root->color);
        if (root->parent != NULL){
            printf(" ParentData[%d],ParentColor[%d]} ", root->parent->data, root->parent->color);
        }else{
            printf("Parent is NULL} ");
        }
        display_inorder(root->right);
    }
}

struct RedBlackNode* insert(struct RedBlackNode* root, int data){
    struct RedBlackNode* new_node;
    new_node = create_node(data);

    root = bst_insert(root, new_node);
    return root;
}
