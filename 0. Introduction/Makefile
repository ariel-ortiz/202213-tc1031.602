# This is my very first Makefile

CC=g++

main: main.o factorial.o
	$(CC) main.o factorial.o -o main

main.o: main.cpp factorial.h
	$(CC) main.cpp -c

factorial.o: factorial.cpp factorial.h
	$(CC) factorial.cpp -c

clean:
	rm -f main main.o factorial.o
