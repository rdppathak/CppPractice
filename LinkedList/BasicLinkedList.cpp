#include "Node.h"

/*
Appends new node at end of list.
*/
int Append(int data, struct Node **root)
{
    struct Node *new_node = NULL;
    struct Node *temp = *root;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (new_node == NULL)
    {
        return -1;
    }

    if (temp == NULL){
        *root = new_node;
    }else{
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    return 1;
}

/*
Prints the elements of LinkedList
*/
void PrintList(struct Node *root)
{
    struct Node *temp;
    temp = root;

    printf("List Elements: ");
    while(temp != NULL){
        printf ("->[%d]", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/*
Inserts node at particular position
*/
void InsertNode(int data, int position, struct Node **root)
{
    struct Node *temp, *prev;
    temp = *root;
    prev = NULL;
    int count = 0;

    struct Node *new_node;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    while (temp != NULL){
        if (count == position){
            if (prev == NULL){
                new_node->next = temp;
                *root = new_node;
            }else{
                new_node->next = temp;
                prev->next = new_node;
            }
        }else{
            prev = temp;
            temp = temp->next;
        }
        count++;
    }
    if (count == position){
        new_node->next =temp;
        prev->next = new_node;
    }
    printf("Error: Invalid insert position\n");
}

/*
Deletes last Node of list
*/
struct Node* DeleteNode(int data, struct Node* root){
    struct Node *temp, *prev, *delete_node;
    temp = root;
    prev = NULL;

    while(temp != NULL){
        if(temp->data == data){
            if (prev == NULL){
                delete_node = temp;
                temp = temp->next;
                free(delete_node);
                return temp;
            }else{
                delete_node = temp;
                prev->next = temp->next;
                return root;
            }
        }
        prev= temp;
        temp=temp->next;
    }
    printf("Error: Element not found\n");
    return root;
}
/*
Get the size of list
*/
int GetSize(struct Node* root){
    struct Node *temp;
    temp = root;
    int size = 0;
    while (temp != NULL){
        size++;
        temp = temp->next;
    }
    return size;
}

// int main()
// {
//     struct Node *root = NULL;
//
//     Append(10, &root);
//     Append(20, &root);
//     InsertNode(30, 1, &root);
//     PrintList(root);
//     printf("Number of elements: %d\n", GetSize(root));
//     root = DeleteNode(40, root);
//     printf("After Delete\n");
//     PrintList(root);
//     printf("Number of elements: %d\n", GetSize(root));
//     return 0;
// }
