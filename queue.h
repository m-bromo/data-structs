#ifndef QUEUE_H  
#define QUEUE_H   

#include <stdbool.h> 

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
    int size;
} Queue;


Queue *create_queue();
bool is_empty(Queue *queue);
int size(Queue *queue);
void insert(Queue *queue, int data);
void pop(Queue *queue);
void print_queue(Queue *queue);

#endif 