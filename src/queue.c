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

bool queue_is_empty(queue *q) {
    return q->size == 0;
}

int queue_size(queue *q) {
    return q->size;
}

void enqueue(queue *q, int data) {
    simple_node *new_node = (simple_node*) malloc(sizeof(simple_node));
    if (new_node == NULL) return;

    new_node->data = data;
    new_node->next = NULL;
    q->size++;

    if (q->head == NULL) { 
        q->head = new_node;
        q->tail = new_node;
        return;
    }

    q->tail->next = new_node;
    q->tail = new_node;
}

void dequeue(queue *q) {
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
