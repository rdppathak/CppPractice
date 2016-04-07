#include <stdio.h>
#include <stdlib.h>

/*
Basic Node structure for Linked List
*/
struct Node
{
    int data;
    struct Node *next;
};

int Append(int, struct Node**);
void PrintList(struct Node*);
void InsertNode(int, int, struct Node**);
struct Node* DeleteNode(int, struct Node*);
int GetSize(struct Node*);

void ReverseList(struct Node**);

struct Node* Merge(struct Node*, struct Node*);

void MoveNode(struct Node**, struct Node**);
