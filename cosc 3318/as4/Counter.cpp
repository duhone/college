// DO NOT MODIFY THIS FILE

#include "Counter.h"
	
Counter::Counter(int initValue) 
{
	value = initValue; 
}

Counter::Counter(const Counter& other)
{
	*this = other;
}

const Counter& Counter::operator=(const Counter& other)
{
	if (this != &other)
	{
		value = other.value;
	}

	return *this;
}

Counter::~Counter()
{
}

void Counter::increament()
{
	value++;
}

int Counter::getValue() const
{
	return value;
}

const Counter operator+(const Counter& ctr1, const Counter& ctr2)
{
	Counter result (ctr1.getValue() + ctr2.getValue());
	return result;
}

const Counter operator-(const Counter& ctr1, const Counter& ctr2)
{
	Counter result (ctr1.getValue() - ctr2.getValue());
	return result;
}

ostream& operator<<(ostream& out, const Counter& obj)
{
	out << obj.getValue();
	return out;
}