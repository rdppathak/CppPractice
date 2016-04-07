#include "Queue.h"

QNode* NewNode(int k){
    QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

Queue* CreateQueue(){
    Queue *q;
    q = (struct Queue*)malloc(sizeof(struct Queue));
    q->rear=NULL;
    q->front=NULL;
    return q;
}

void Enqueue(Queue *queue, int k){
    QNode *temp = NewNode(k);
    temp->key = k;
    temp->next = NULL;
    if(queue->rear == NULL){
        queue->rear = temp;
        queue->front = temp;
        return;
    }

    queue->rear->next = temp;
    queue->rear = temp;
}

QNode* Dequeue(Queue *queue){

    if (queue->front == NULL){
        return NULL;
    }

    QNode *temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL){
        queue->rear = NULL;
    }
    return temp;
}

void PrintQueue(Queue *queue){
    QNode *temp;
    temp = queue->front;

    printf("Queue items: ");
    while(temp != NULL){
        printf(" [%d]", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Queue *q = CreateQueue();
    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);
    Enqueue(q, 40);
    PrintQueue(q);
    printf("Queue Front: [%d], Queue Rear: [%d]\n", q->front->key, q->rear->key);
    QNode * item;
    item = Dequeue(q);
    printf("Item Dequeued: %d\n", item->key);
    PrintQueue(q);
    item = Dequeue(q);
    printf("Item Dequeued: %d\n", item->key);
    PrintQueue(q);
    return 0;
}
