#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct List {
    Node* dummy_head;
    Node* back;
}List;

int isEmpty(List* l) {
    return l->dummy_head->next == NULL;
}
Node* createNode(int val, Node* p) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) return NULL;
    newNode->data = val;
    newNode->next = p;
    return newNode;
}
void pushFront(List* l, Node* n) {
    if(l == NULL || n == NULL) return;
    n->next = l->dummy_head->next;
    l->dummy_head->next = n;
    if(l->back == l->dummy_head)    l->back = n;
}

void deleteFront(List* l) {
    if(l == NULL) return;
    if(isEmpty(l)) return;
    Node* front = l->dummy_head->next;
    l->dummy_head->next = front->next;
    if(front == l->back)    l->back = l->dummy_head;
    free(front);
}

void pushBack(List* l, Node* n) {
    if(l == NULL || n == NULL) return;
    l->back->next = n;
    l->back = n;
}

void deleteBack(List* l) {
    if(l == NULL) return;
    if(isEmpty(l)) return;
    Node* temp = l->dummy_head;
    while(temp->next->next != NULL) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    l->back = temp;
}

Node* find(List* l, int key) {
    if(l == NULL) return NULL;
    if(isEmpty(l)) return NULL;
    Node* temp = l->dummy_head;
    while(temp->next != NULL) {
        if(temp->next->data == key) return temp->next;
        temp = temp->next;
    }
    return NULL;
}

Node* insertAfter(List* l, Node* n, Node* newNode) {
    if(l == NULL || n == NULL || newNode == NULL) return NULL;
    newNode->next = n->next;
    n->next = newNode;
    if(l->back == n) l->back = newNode; 
    return newNode;
}

void deleteNode(List* l, Node* n) {
    if(l == NULL || n == NULL) return;
    Node* before = l->dummy_head;
    while(before->next != NULL) {
        if(before->next == n) break;
        before = before->next;
    }
    if(before->next == NULL) return; // Node wasn't found
    before->next = n->next;
    if(l->back == n)    l->back = before;
    free(n);
}

List* createEmptyList(void) {
    List* newList = (List*)malloc(sizeof(List));
    newList->dummy_head = (Node*)malloc(sizeof(Node));
    newList->dummy_head->next = NULL;
    newList->back = newList->dummy_head;
    return newList;
}

void deleteList(List* l) {
    if (l == NULL) return;
    Node* current = l->dummy_head->next;
    Node* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(l->dummy_head);
    free(l);
}
#endif