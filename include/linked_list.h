#ifndef LINKED_LIST_H
#define LINKEDI_LIST_H

#include<stdlib.h>
#include "node.h"


typedef struct linked_list {
    simple_node *head;
    simple_node *tail;
    int size;
} linked_list;

linked_list *create_linked_list();
int linked_list_size(linked_list *l);
void prepend(linked_list *l, int data);
void append(linked_list *l, int data);
void delete_first(linked_list *l);
void delete_last(linked_list *l);
void print_linked_list(linked_list *l);

#endif