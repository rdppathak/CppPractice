#include "Node.h"


void ReverseList(struct Node **root)
{
    struct Node *prev = NULL;
    struct Node *curr = *root;
    struct Node *next;

    while (curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *root = prev;
}


int main(){
    struct Node *root;

    Append(10, &root);
    Append(7, &root);
    Append(9, &root);
    Append(2, &root);
    Append(4, &root);
    Append(6, &root);

    printf ("Original list: \n");
    PrintList(root);

    ReverseList(&root);

    printf("Reversed list: \n");
    PrintList(root);

    return 0;
}
