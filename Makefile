CC = clang
CFLAGS = -Wall -Wextra
LDLIBS = -lm


all : main

main : list.o main.o
	$(CC) $(CFLAGS) list.o main.o -o main

list.o : list.c list.h
	$(CC) $(CFLAGS) -c list.c

main.o : main.c list.h
	$(CC) $(CFLAGS) -c main.c

run : main
	./main

clean:
	rm -f *.o
