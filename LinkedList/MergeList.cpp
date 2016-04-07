#include "Node.h"


struct Node* Merge(struct Node *a, struct Node *b)
{
    struct Node dummy;
    struct Node* tail = NULL;

    tail = &dummy;

    dummy.next = NULL;

    while(1){
        if (a == NULL){
            tail->next = b;
            break;
        }else if (b == NULL){
            tail->next = a;
            break;
        }

        if (a->data <= b->data){
            MoveNode(&(tail->next), &a);
        }
        else{
            MoveNode(&(tail->next), &b);
        }
        tail=tail->next;
    }

    return (dummy.next);
}

void MoveNode(struct Node** destRef, struct Node** sourceRef)
{
  struct Node* newNode = *sourceRef;

  *sourceRef = newNode->next;

  newNode->next = *destRef;

  *destRef = newNode;
}

int main()
{
    struct Node *result;
    struct Node *a;
    struct Node *b;

    Append(10, &a);
    Append(8, &a);
    Append(6, &a);
    Append(4, &a);

    Append(9, &b);
    Append(7, &b);
    Append(5, &b);
    Append(3, &b);

    printf("List a ");
    PrintList(a);

    printf("List b ");
    PrintList(b);

    result = Merge(a,b);

    printf("Merged list: ");
    PrintList(result);
    return 0;
}
