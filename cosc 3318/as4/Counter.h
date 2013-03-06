// DO NOT MODIFY THIS FILE

#include <iostream.h>

class Counter
{
public:
	Counter(int initValue = 0);
	// Purpose: -
	// Requirement: -
	// Promises: -
	// Exception: -

	Counter(const Counter& other);

	virtual const Counter& operator=(const Counter& other);

	virtual ~Counter();

	virtual void increament();
	// Purpose: Increases the value of the counter by one
	// Requirement: -
	// Promises: -
	// Exception: -

	virtual int getValue() const;
	// Purpose: Returns the current value of the counter
	// Requirement: -
	// Promises: - 
	// Exception: -

private:
	int value;
};

const Counter operator+(const Counter& ctr1, const Counter& ctr2);
const Counter operator-(const Counter& ctr1, const Counter& ctr2);

ostream& operator<<(ostream& out, const Counter& obj);
