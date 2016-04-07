#include "Node.h"

void swap_node(struct Node **root, int x, int y)
{
    struct Node *node_ref;
    struct Node *prevx = NULL;
    struct Node *prevy = NULL;
    struct Node *prev = NULL;
    struct Node *currx = NULL;
    struct Node *curry = NULL;

    node_ref =*root;

    while (node_ref != NULL){
        if (currx != NULL && curry != NULL){
            break;
        }
        if (node_ref->data == x){
            prevx = prev;
            currx= node_ref;
        }
        if (node_ref->data == y){
            prevy = prev;
            curry = node_ref;
        }
        prev = node_ref;
        node_ref = node_ref->next;
    }

    if (currx == NULL || curry == NULL){
        printf ("Error: Either element not present, can't swap\n");
        return;
    }

    if (prevx == NULL){
        *root = curry;
    }else{
        prevx->next = curry;
    }

    if (prevy == NULL){
        *root = currx;
    }else{
        prevy->next = currx;
    }

    struct Node *temp;
    temp = currx->next;
    currx->next = curry->next;
    curry->next = temp;

}

int main(){
    struct Node *root=NULL;

    Append(10, &root);
    Append(7, &root);
    Append(9, &root);
    Append(2, &root);
    Append(4, &root);
    Append(6, &root);

    printf ("List before SWAP: \n");
    PrintList(root);

    swap_node(&root, 7, 4);

    printf ("List after SWAP: \n");
    PrintList(root);

    return 0;
}
