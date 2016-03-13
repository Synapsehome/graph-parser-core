kurs-all: main_obj main_link

main_obj: main.c graphio.c linked_list.c linked_list.h
	gcc -c main.c graphio.c linked_list.c

main_link:
	gcc main.o graphio.o linked_list.o -o run
