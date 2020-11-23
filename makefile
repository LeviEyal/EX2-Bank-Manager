#variables:
CC = gcc
FLAGS = -Wall
AR = ar

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

#Creates a static library
mymaths: libMyBank.a

.PHONY: all clean

clean: 
	rm -f *.o *.a *.so maind mains