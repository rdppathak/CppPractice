#include "Node.h"

void rotate_list(struct Node** ref, int rotation)
{
    if (rotation == 0)
        return;

    if (*ref == NULL)
        return;

    struct Node *current = *ref;
    int count = 1;
    while (count < rotation && current != NULL){
        current = current->next;
        count++;
    }

    struct Node *kth_node = current;

    while (current->next != NULL){
        current = current->next;
    }

    current->next = *ref;
    *ref = kth_node->next;

    kth_node->next = NULL;
}

int main()
{
    struct Node *root;
    Append(10, &root);
    Append(20, &root);
    Append(30, &root);
    Append(40, &root);
    Append(50, &root);
    Append(60, &root);

    printf ("Before rotation: \n");
    PrintList(root);
    rotate_list(&root, 4);
    printf("After rotation: \n");
    PrintList(root);




    return 0;
}
