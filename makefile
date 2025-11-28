run:
	gcc src/queue.c src/stack.c src/linked_list.c main.c -Iinclude -o main
	./main
