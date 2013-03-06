#ifndef COUNTER_H
#define COUNTER_H
// This class models a Counter that holds a value and allows you
// to increment, decrement and reset.

// An exception class
class Invalid
{
};

class Counter
{
public:
	Counter();
	// Purpose:
	// Requirements:
	// Promises:
	// Exception:

	virtual ~Counter();
	// Purpose:
	// Requirements:
	// Promises:
	// Exception:

	Counter(const Counter& other);
	// Purpose:
	// Requirements:
	// Promises:
	// Exception:

	virtual const Counter& operator=(const Counter& other);
	// Purpose:
	// Requirements:
	// Promises:
	// Exception:

	virtual bool operator==(const Counter& other) const;
	// Purpose:
	// Requirements:
	// Promises:
	// Exception:

	int getCounterValue() const;
	// Purpose:
	// Requirements:
	// Promises:
	// Exception:

	virtual Counter operator++();
	// Purpose:
	// Requirements:
	// Promises:
	// Exception:

	virtual Counter operator++(int);
	// Purpose:
	// Requirements:
	// Promises:
	// Exception:

	virtual Counter operator--();
	// Purpose:
	// Requirements:
	// Promises:
	// Exception:

	virtual Counter operator--(int);
	// Purpose:
	// Requirements:
	// Promises:
	// Exception:

	virtual void reset(); 
	// Purpose:
	// Requirements:
	// Promises:
	// Exception:
private:
	int value;
};
#endif COUNTER_H
