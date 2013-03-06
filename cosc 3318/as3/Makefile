#!/bin/csh
GCC=/usr/local/bin/g++ -I. -I/buffalo/c/cosc155g/COSC4318/ASSIGN3 
LIB=-L/buffalo/c/cosc155g/COSC4318/ASSIGN3 -lCtr

all : assign3

ModCounter.o : ModCounter.h ModCounter.cpp
	$(GCC) -c ModCounter.cpp

assign3 : libCtr.a assign3.cpp ModCounter.o
	$(GCC) -o assign3 assign3.cpp *.o $(LIB)

clean :
	/bin/rm -f *.o assign3
