kurs-all: main_obj main_link

main_obj: main.c graphio.c
	gcc -c main.c graphio.c

main_link:
	gcc main.o graphio.o -o run
