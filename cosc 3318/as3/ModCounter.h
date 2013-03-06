#include "Counter.h"

// The ModuloCounter class has an upper limit 
// of value that it will never exceed. 
// (The limit must be greater than zero).
// Increment will allow the counters value to increase, but
// no more than limit - 1. Decrement will allow the counter
// decrease its value, but no less than zero (It will 
// roll over to limit - 1, if decrement called when value is 0).
// Comparing two counters must return true only if the limits
// of the counter are the same and the counter values are same.
// If limits are same and values are not, will return false. If
// limits are not same, throw Invalid exception.
// Assignment must be allowed only if the limits are the
// same. If limits are not same, throw Invalid exception.

class ModCounter : public Counter
{
public:
	ModCounter(int limit);
	// Purpose: create a new modcounter object
	// Requirements:an int that specifies the mod value of the counter
	// Promises:will create a new modcounter
	// Exception:

	virtual ~ModCounter();
	// Purpose:to destroy a modcounter
	// Requirements:
	// Promises:will free all memory used by the counter
	// Exception:

	ModCounter(const ModCounter& other);
	// Purpose:copy constructor
	// Requirements:a referance to another modcounter
	// Promises: will make another counter with same limit and value as other
	// Exception:

	virtual const Counter& operator=(const Counter& other);
	// Purpose:assignment operator
	// Requirements:a referance to another plain counter or modcounter object
	// Promises:will make another counter with same limit and value as other
	//		if other is a modcounter
	// Exception: will throw exception if called

	virtual const ModCounter& operator=(const ModCounter& other);
	// Purpose:assignment operator
	// Requirements:a referance to another modcounter object
	// Promises:will make another counter with same limit and value as other
	// Exception:

	virtual bool operator==(const Counter& other) const;
	// Purpose:will compare objects this and other
	// Requirements:a referance to another modcounter object
	// Promises:will return true if objects are completly equal.
	//		will return false if limit is equal but value of counter is not
	// Exception:will throw an exception if limits are not equal or if other is not a
	//		modcounter

	virtual Counter operator++();
	// Purpose:increment counter;
	// Requirements:
	// Promises:will increment the value of counter and return the incremented value
	// Exception:

	virtual Counter operator++(int);
	// Purpose:increment counter;
	// Requirements:
	// Promises:will increment the value of counter and return the old value of counter
	// Exception:

	virtual Counter operator--();
	// Purpose:decrement counter;
	// Requirements:
	// Promises:will decrement the value of counter and return the incremented value
	// Exception:

	virtual Counter operator--(int);
	// Purpose:decrement counter;
	// Requirements:
	// Promises:will decrement the value of counter and return the old value of counter
	// Exception:
private:
	int maxval;

};
