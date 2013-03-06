#!/bin/csh
GCC=/usr/local/bin/gcc -I.
LIB= -L/buffalo/c/cosc155g/COSC3318/ASSIGN1 -L/usr/shlib -lTimer -lstdc++ -lpthread

all : a1 

Microwave.o : Microwave.h Microwave.cpp
	$(GCC) -I/buffalo/c/cosc155g/COSC3318/ASSIGN1 -c Microwave.cpp

a1 : a1.cpp Microwave.o 
	$(GCC) -I/buffalo/c/cosc155g/COSC3318/ASSIGN1 -o a1 a1.cpp Microwave.o $(LIB)

clean :
	/bin/rm -f a1
	/bin/rm -f *.o
