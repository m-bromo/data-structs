#ifndef STACK_H  
#define STACK_H

#include "node.h"

typedef struct stack {
    simple_node *head;
    int size;
} stack;

stack* create_stack();
int stack_size(stack *s);
void push(stack *s, int data);
void pop(stack *s);
void print_stack(stack *s);

#endif 