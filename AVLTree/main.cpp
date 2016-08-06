#include "Node.h"

int main(){
    struct Node *root=NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    printf("Pre Order traversal of tree is as follows:\n");
    pre_order_traversal(root);
    printf("\n");

    root = delete_node(root, 20);

    printf("Pre Order traversal of tree is as follows:\n");
    pre_order_traversal(root);
    printf("\n");
    return 0;
}
