#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack *create_stack() {
    stack *s = (stack*)malloc(sizeof(stack));
    if (s != NULL) {
        s->head = NULL;
        s->size = 0;
    }

    return s;
}

int stack_size(stack *s) {
    return s->size;
}

void push(stack *s, int data) {
    simple_node *new_node = (simple_node*)malloc(sizeof(simple_node));
    if (new_node == NULL) return;

    new_node->data = data;
    s->size++;

    new_node->next = s->head;
    s->head = new_node;
}

void pop(stack *s) {
    if (s->head == NULL) return;

    s->size--;

    simple_node *aux = s->head;
    s->head = s->head->next;

    free(aux);
}

void print_stack(stack *s) {
    simple_node *aux = s->head;

    while (aux != NULL) {
        printf("[%d] -> ", aux->data);
        aux = aux->next;
    }
    printf("NULL\n");
}