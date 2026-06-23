#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"

typedef struct Queue {
    List* l;
    int size;
    void(*enqueue)(struct Queue* self, int);
    void(*dequeue)(struct Queue* self);
    int(*front)(struct Queue* self);
} Queue;

void enqueue(Queue* q, int n) {
    pushBack(q->l, createNode(n, NULL));
    q->size++;
}

void dequeue(Queue* q) {
    if (!isEmpty(q->l)) {
        deleteFront(q->l);
        q->size--;
    }
}

int front(Queue* q) {
    if (isEmpty(q->l)) {
        return -1; 
    }
    return q->l->dummy_head->next->data;
}

Queue* createQueue(void) {
    Queue* newQ = (Queue*)malloc(sizeof(Queue));
    newQ->l = createEmptyList();
    newQ->size = 0;
    newQ->enqueue = enqueue;
    newQ->dequeue = dequeue;
    newQ->front = front;
}

void deleteQueue(Queue* q) {
    deleteList(q->l);
    free(q);
}
#endif