//Name:  Eric Duhon
//SSN:   453-97-8531
//Home Work 2


// A n ModuloCounter counts in the range 0 to n-1. Each call to 
// increment increases the count by 1 and each call to decrement
// decreases the count by 1. If the counter's value is n-1, an
// increment request will result in a value of 0. Similary,
// a decrement on a counter with value of 0 will result in a 
// value of n-1.

class ModuloCounter 
{
public:
	ModuloCounter(int base);
		//Purpose: To construct a new counter with specified base
		//Requirement:	base must be an int.
		//Promise: will construct a modulo counter of  base specified
		//Exception: 
	ModuloCounter(const ModuloCounter& counterarg);
		//Purpose: To construct a new counter with same state as counterarg
		//Requirement: a referance to another ModuloCounter.
		//Promise: will construct a new counter with same state as counterarg
		//Exception: 
	ModuloCounter& operator=(const ModuloCounter& counterarg);
		//Purpose: To make counter have same state as counterarg
		//Requirement:a referance to another ModuloCounter.
		//Promise: will change all values of counter to match those of counterarg
		//Exception: 
	~ModuloCounter();
		//Purpose: To destroy the counter
		//Requirement:
		//Promise: will destroy the counter
		//Exception: 
	void increment();
		//Purpose: To increment the current count of the counter
		//Requirement:
		//Promise: will increment the current count of the counter
		//Exception: 
	void decrement();
		//Purpose: To decrement the current count of the counter
		//Requirement:
		//Promise: will decrement the current count of the counter
		//Exception: 
	int getCounterValue() const;
		//Purpose: To return the current count
		//Requirement:
		//Promise: will not modify the state of the counter
		//Exception: 
	static int getNumberofModuloCounters();
		//Purpose: To return the number of counters created
		//Requirement:
		//Promise: will return the number of counters created
		//Exception: 

private:
	static int numcounters;
	int counterbase;
	int currentcount;

};
