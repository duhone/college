//Name:  Eric Duhon
//SSN:   453-97-8531
//Home Work 2
#include "ModuloCounter.h"

int ModuloCounter::numcounters = 0;


ModuloCounter::ModuloCounter(int base)
{
	numcounters++;
	if(base <=0 ) base = 1;
	counterbase = base;
	currentcount = 0;
}

ModuloCounter::ModuloCounter(const ModuloCounter& counterarg)
{
	numcounters++;
	counterbase = counterarg.counterbase;
	currentcount = counterarg.currentcount;;
}

ModuloCounter::~ModuloCounter()
{
	numcounters--;
}

ModuloCounter& ModuloCounter::operator=(const ModuloCounter& counterarg)
{
	if(this != &counterarg)
	{
		counterbase = counterarg.counterbase;
		currentcount = counterarg.currentcount;
	}
	return *this;
}

int ModuloCounter::getNumberofModuloCounters()
{
	return numcounters;
}

int ModuloCounter::getCounterValue() const
{
	return currentcount;
}

void ModuloCounter::increment()
{
	currentcount++;
	currentcount %= counterbase;
}

void ModuloCounter::decrement()
{
	currentcount--;
	if(currentcount < 0) currentcount = counterbase-1;

}



