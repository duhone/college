#!/bin/csh
GCC=/usr/local/bin/gcc -I.
LIB=-lstdc++

all : modCounterUser

ModuloCounter.o : ModuloCounter.h ModuloCounter.cc
	$(GCC) -c ModuloCounter.cc

modCounterUser : modCounterUser.cc ModuloCounter.o
	$(GCC) -o modCounterUser modCounterUser.cc ModuloCounter.o $(LIB)

clean :
	/bin/rm -f modCounterUser ModuloCounter.o
