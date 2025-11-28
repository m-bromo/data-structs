#include <stdio.h>
#include "queue.h"
#include "stack.h"
#include "linked_list.h"

int main() {
    queue *queue = create_queue();
    
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    print_queue(queue);
    
    dequeue(queue);

    print_queue(queue);


    stack *s = create_stack();

    push(s, 1);
    push(s, 2);
    push(s, 3);

    print_stack(s);

    pop(s);

    print_stack(s);

    linked_list *l = create_linked_list();

    append(l, 1);
    append(l, 2);
    append(l, 3);
    prepend(l, 5);
    prepend(l, 6);

    print_linked_list(l);
    printf("%d", l->head->data);
}
