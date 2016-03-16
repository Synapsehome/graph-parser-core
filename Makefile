all: main_obj main_link

main_obj: main.c graphio.c linked_list.c linked_list.h matrix.c matrix.h
	gcc -c main.c graphio.c linked_list.c generate.c matrix.c

main_link:
	gcc main.o graphio.o linked_list.o generate.o matrix.o -o run

clean:
	rm graphio.o main.o linked_list.o generate.o matrix.o run
