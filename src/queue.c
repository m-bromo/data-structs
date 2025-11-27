#include <stdio.h>
#include <stdlib.h>
#include "queue.h" 

Queue *create_queue() {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    if (queue != NULL) {
        queue->head = NULL;
        queue->tail = NULL;
        queue->size = 0;
    }
    return queue;
}

bool is_empty(Queue *queue) {
    return queue->size == 0;
}

int size(Queue *queue) {
    return queue->size;
}

void insert(Queue *queue, int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) return;

    newNode->data = data;
    newNode->next = NULL;
    queue->size++;

    if (queue->head == NULL) { 
        queue->head = newNode;
        queue->tail = newNode;
        return;
    }

    queue->tail->next = newNode;
    queue->tail = newNode;
}

void pop(Queue *queue) {
    if (queue->head == NULL) return;

    Node *aux = queue->head;
    queue->head = queue->head->next;
    free(aux);
    
    queue->size--;

    if (queue->head == NULL) {
        queue->tail = NULL;
    }
}

void print_queue(Queue *queue) {
    Node *aux = queue->head;
    while(aux != NULL) {
        printf("[%d] -> ", aux->data);
        aux = aux->next;
    }
    printf("NULL\n");
}