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
bool is_empty(queue *q);
int size(queue *q);
void insert(queue *q, int data);
void pop(queue *q);
void print_queue(queue *q);

#endif 