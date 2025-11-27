#include <stdio.h>
#include <stdlib.h>
#include "queue.h" 

queue *create_queue() {
    queue *q = (queue*) malloc(sizeof(queue));
    if (q != NULL) {
        q->head = NULL;
        q->tail = NULL;
        q->size = 0;
    }
    return q;
}

bool is_empty(queue *q) {
    return q->size == 0;
}

int size(queue *q) {
    return q->size;
}

void insert(queue *q, int data) {
    simple_node *newNode = (simple_node*) malloc(sizeof(simple_node));
    if (newNode == NULL) return;

    newNode->data = data;
    newNode->next = NULL;
    q->size++;

    if (q->head == NULL) { 
        q->head = newNode;
        q->tail = newNode;
        return;
    }

    q->tail->next = newNode;
    q->tail = newNode;
}

void pop(queue *q) {
    if (q->head == NULL) return;

    simple_node *aux = q->head;
    q->head = q->head->next;
    free(aux);
    
    q->size--;

    if (q->head == NULL) {
        q->tail = NULL;
    }
}

void print_queue(queue *q) {
    simple_node *aux = q->head;
    while(aux != NULL) {
        printf("[%d] -> ", aux->data);
        aux = aux->next;
    }
    printf("NULL\n");
}
