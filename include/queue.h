#ifndef QUEUE_H  
#define QUEUE_H   

#include <stdbool.h>
#include "node.h"

typedef struct queue {
    simple_node *head;
    simple_node *tail;
    int size;
} queue;

queue *create_queue();
bool queue_is_empty(queue *q);
int queue_size(queue *q);
void enqueue(queue *q, int data);
void dequeue(queue *q);
void print_queue(queue *q);

#endif 