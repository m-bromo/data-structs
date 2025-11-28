#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

linked_list *create_linked_list() {
    linked_list *l = (linked_list*)malloc(sizeof(linked_list));

    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

    return l;
}

int linked_list_size(linked_list *l) {
    return l->size;
}

void append(linked_list *l, int data) {
    simple_node *new_node = (simple_node*)malloc(sizeof(simple_node));
    new_node->data = data;
    new_node->next = NULL;
    l->size++;

    if (l->head == NULL) {
        l->head = new_node;
        l->tail = new_node;
        return;
    }

    l->tail->next = new_node;
    l->tail = new_node;
}

void prepend(linked_list *l, int data) {
    simple_node *new_node = (simple_node*)malloc(sizeof(simple_node));
    new_node->data = data;
    l->size++;

    if (l->head == NULL) {
        new_node->next = NULL;
        l->head = new_node;
        l->tail = new_node;
        return;
    }

    new_node->next = l->head;
    l->head = new_node;
}

void delete_first(linked_list *l) {
    if (l->head == NULL) return;

    simple_node *aux = l->head;
    l->head = l->head->next;
    
    if (l->head == NULL) {
        l->tail = NULL;
    }

    free(aux);
    l->size--;
}

void delete_last(linked_list *l) {
    if (l->head == NULL) return;

    if (l->head->next == NULL) {
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
        l->size--;
        return;
    }

    simple_node *current = l->head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    free(current->next);
    current->next = NULL;
    l->tail = current;
    l->size--;
}


void print_linked_list(linked_list *l) {
    simple_node *aux = l->head;

    while (aux != NULL) {
        printf("[%d] -> ", aux->data);
        aux = aux->next;
    }
    printf("NULL\n");
}
