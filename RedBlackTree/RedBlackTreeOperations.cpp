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
    check_voilations(root, new_node);
    return root;
}


void rotate_right(struct RedBlackNode *&root, struct RedBlackNode *&pt){
    struct RedBlackNode *pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != NULL){
        pt->left->parent = pt;
    }

    if(pt_left->parent == NULL){
        root = pt_left;
    }
    else if (pt == pt_left->parent->left){
        pt->parent->left = pt_left;
    }else{
        pt->parent->right = pt_left;
    }

    pt_left->right = pt;
    pt->parent = pt_left;
}

void rotate_left(struct RedBlackNode *&root, struct RedBlackNode *&pt){
    struct RedBlackNode *pt_right = pt->right;

    pt->right = pt_right->left;
    if (pt->right != NULL){
        pt->right->parent = pt;
    }

    pt_right->parent = pt->parent;

    if(pt->parent ==NULL){
        root = pt_right;
    }
    else if(pt == pt->parent->right){
        pt->parent->right = pt_right;
    }else{
        pt->parent->left = pt_right; 
    }

    pt_right->left = pt;
    pt->parent = pt_right;
}

void check_voilations(struct RedBlackNode *&root, struct RedBlackNode *&pt){

    struct RedBlackNode* parent_pt = NULL; 
    struct RedBlackNode* grandparent_pt = NULL;

    while(pt!=root && pt->color!=BLACK && pt->parent->color == RED){
        parent_pt = pt->parent;
        grandparent_pt = parent_pt->parent;

        if (parent_pt == grandparent_pt->left){
            //Parent of pt is left child of grandparent
            struct RedBlackNode* uncle_pt = grandparent_pt->right;

            if (uncle_pt!=NULL && uncle_pt->color==RED){
                grandparent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grandparent_pt;
            }else{
                if (pt == parent_pt->right){
                    rotate_left(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotate_right(root, grandparent_pt);
                //Swap the colors of parent and grandparent after right rotate
                bool temp;
                temp = parent_pt->color;
                parent_pt->color = grandparent_pt->color;
                grandparent_pt->color = temp;

                pt = parent_pt;
            }
        }else{
            //Parent of pt is right child of grandparent
            struct RedBlackNode* uncle_pt = grandparent_pt->left;

            if (uncle_pt!=NULL && uncle_pt->color !=RED){
                grandparent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grandparent_pt;
            }else{
                if (pt == parent_pt->left){
                    rotate_right(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                rotate_left(root, grandparent_pt);
                //Swap the colors of parent and grandparent after right rotate
                bool temp;
                temp = parent_pt->color;
                parent_pt->color = grandparent_pt->color;
                grandparent_pt->color = temp;

                pt = parent_pt;
            }
        }
    }
    //Always change the color of root node to BLACK.
    root->color = BLACK;
}
