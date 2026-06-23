#ifndef STACK_H
#define STACK_H
#include "list.h"

typedef struct Stack {
    List* l;
    int size;
    void(*push)(struct Stack *self, int);
    int(*top)(struct Stack *self);
    void(*pop)(struct Stack *self);
} Stack;

void push(Stack* s, int num) {
    pushFront(s->l, createNode(num, s->l->dummy_head->next));
    s->size++;
}

int top(Stack* s) {
    if (isEmpty(s->l)) {
        return -1; 
    }
    return s->l->dummy_head->next->data;
}

void pop(Stack *s) {
    if (!isEmpty(s->l)) {
        deleteFront(s->l);
        s->size--;
    }
}

Stack* createStack(void) {
    List* newList = createEmptyList();
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->l = newList;
    newStack->size = 0;
    newStack->push = push;
    newStack->top = top;
    newStack->pop = pop;
    return newStack;
}

void deleteStack(Stack* s) {
    deleteList(s->l);
    free(s);
}

#endif