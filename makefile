CC=gcc

main: main.o PQ.o
	$(CC) main.o PQ.o -o main.out

PQ.o: PQ.c
	$(CC) -c PQ.c -o PQ.o

main.o: main.c
	$(CC) -c main.c -o main.o
