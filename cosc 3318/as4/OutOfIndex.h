// DO NOT MODIFY THIS FILE

#ifndef OUTOFINDEX_H
#define OUTOFINDEX_H

// This class simly keeps a value of an index. Indicates an exception
// condition that has occured with any container when tried to access
// with the said index.

class OutOfIndex
{
public:
	OutOfIndex(int indexValue);
	// Purpose: Initializes the exception object with the index that caused the 
	// voilation.
	// Requirement: -
	// Promises: -
	// Exception: -

	int getIndex() const;
	// Purpose: Returns the index value that caused this exception to occur.
	// Requirement: -
	// Promises: -
	// Exception: -

private:
	int index;
};

ostream& operator<<(ostream& out, const OutOfIndex& exception);

#endif