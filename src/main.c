#include <stdio.h>
#include "queue.h"

int main() {
    Queue *queue = create_queue();
    
    insert(queue, 10);
    insert(queue, 20);
    insert(queue, 30);

    print_queue(queue);
    
    pop(queue);

    print_queue(queue);
    
    return 0;
}