// DO NOT MODIFY THIS FILE

#include <iostream.h>
#include "OutOfIndex.h"

OutOfIndex::OutOfIndex(int indexValue)
{
	index = indexValue;
}

OutOfIndex::getIndex() const
{
	return index;
}

ostream& operator<<(ostream& out, const OutOfIndex& exception)
{
	out << "Invalid index:" << exception.getIndex() << endl;

	return out;
}