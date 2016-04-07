#include <stdio.h>
#include <stdlib.h>

struct QNode{
    int key;
    struct QNode *next;
};

struct Queue{
    struct QNode *rear, *front;
};

QNode* NewNode(int k);
Queue* CreateQueue();
