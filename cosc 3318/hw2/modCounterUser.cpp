// DO NOT MODIFY THIS FILE


// Your code must produce the same result as given in output

// Due date: July 30th 6:10PM in class.
// Turnin  the following:
// Hard copy of ModuloCounter.h, ModuloCounter.cpp with your
// name and student id.

// Read the file ~cosc155g/COSC4318/comments for comments requirements.

// DO NOT MODIFY THIS FILE
   
#include "ModuloCounter.h"
#include <iostream.h>

void printCounterInfo(const ModuloCounter& theCounter);
	// prints the Value of the Counter

void printCounterValueAndCount_1(const ModuloCounter theCounter);
	// prints the Value of the Counter and the Number of Counters
	// Takes a ModuloCounter object by Value

void printCounterValueAndCount_2(const ModuloCounter& theCounter);
	// prints the Value of the Counter and the Number of Counters
	// Takes a ModuloCounter object by Reference

// The objective of above functions is to see the effect of
// taking an argument object by value and by reference

void main()
{
	ModuloCounter counter(3);

	printCounterInfo(counter);

	cout << "Incrementing - ";
	counter.increment();
	printCounterInfo(counter);

	cout << "Incrementing - ";
	counter.increment();
	printCounterInfo(counter);

	cout << "Incrementing - ";
	counter.increment();
	printCounterInfo(counter);

	cout << "Decrementing - ";
	counter.decrement();
	printCounterInfo(counter);

	cout << "Number of Counters while in main: " << 
			ModuloCounter::getNumberofModuloCounters() << endl;

	{	// Starts a new scope here
		ModuloCounter anotherCounter(4);

		cout << "Number of Counters while in inner scope: " <<
			anotherCounter.getNumberofModuloCounters() << endl;

	}	// End of the inner scope... 
		// the object anotherCounter is destroyed

	cout << "Number of Counters while in main: " << 
			ModuloCounter::getNumberofModuloCounters() << endl;

	printCounterValueAndCount_1(counter);

	cout << "Number of Counters while in main: " << 
			ModuloCounter::getNumberofModuloCounters() << endl;

	printCounterValueAndCount_2(counter);

	cout << "Number of Counters while in main: " << 
			ModuloCounter::getNumberofModuloCounters() << endl;
}


void printCounterInfo(const ModuloCounter& theCounter)
	// prints the Value of the Counter
{
	cout << "Counter Value is " << 
			theCounter.getCounterValue() << endl;
}

void printCounterValueAndCount_1(const ModuloCounter theCounter)
	// prints the Value of the Counter and the Number of Counters
	// Takes a ModuloCounter object by Value
{
	cout << "Counter Value is " <<
			theCounter.getCounterValue() << endl;

	cout << "Number of Counters while in printCounterValueAndCount_1: " << 
		ModuloCounter::getNumberofModuloCounters() << endl;
}

void printCounterValueAndCount_2(const ModuloCounter& theCounter)
	// prints the Value of the Counter and the Number of Counters
	// Takes a ModuloCounter object by Reference
{
	cout << "Counter Value is " <<
			theCounter.getCounterValue() << endl;

	cout << "Number of Counters while in printCounterValueAndCount_2: " << 
		ModuloCounter::getNumberofModuloCounters() << endl;
}
