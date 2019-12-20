
all: main

main: oo.o main.c
	gcc -o main main.c oo.o

oo.o: oo.c oo.h
	gcc -c oo.c

