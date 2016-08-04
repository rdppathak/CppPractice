#include "RedBlackNode.h"

int main(){
    printf("Constructing Red Black Tree\n");
    struct RedBlackNode *root;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    printf("Inorder tree structure:\n");
    display_inorder(root);
    printf("\n");
    return 0;
}
