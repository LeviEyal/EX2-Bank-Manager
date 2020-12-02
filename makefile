#variables:
CC = gcc
FLAGS = -Wall
AR = ar
.PHONY: all clean

all: main

main: main.o libMyBank.a 
	$(CC) $(FLAGS) -o main main.o libMyBank.a 

# Creating static lib
libMyBank.a: myBank.o 
	$(AR) -rcs libMyBank.a myBank.o 

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c

clean: 
	rm -f *.o *.a main
run: main
	rm -f *.o *.a
	./main