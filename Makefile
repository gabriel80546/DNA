CC=gcc
CFLAGS= -std=c89

program: main.o
	$(CC) $(CFLAGS) -o dna main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f program main.o
