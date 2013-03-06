//Name:  Eric Duhon

#include "ModCounter.h"


ModCounter::ModCounter(int limit)
{
	if(limit <= 0) maxval = 1;
	else maxval = limit;
}

ModCounter::ModCounter(const ModCounter& other) : Counter(other)
{
	maxval = other.maxval;
}

ModCounter::~ModCounter()
{
}

const Counter& ModCounter::operator =(const Counter& other)
{
	//try to cast to modcounter
	const ModCounter* const otherref = dynamic_cast<const ModCounter* const>(&other);	
	//if not a modcounter then throw exception
	if(otherref == 0)
		throw Invalid();
	maxval = otherref->maxval;
	Counter::operator =(other);
	return *this;
}

const ModCounter& ModCounter::operator =(const ModCounter& other)
{
	maxval = other.maxval;
	Counter::operator =(other);
	return *this;
}
Counter ModCounter::operator ++()
{
	int temp;
	temp = getCounterValue();
	Counter::operator ++();
	if(temp >= maxval-1) reset();
	return *this;
}

Counter ModCounter::operator ++(int)
{
	ModCounter tempcount(*this);
	int temp;
	temp = getCounterValue();
	Counter::operator ++();
	if(temp >= maxval-1) reset();
	return tempcount;
}

Counter ModCounter::operator --()
{
	int temp;
	Counter::operator --();
	temp = getCounterValue();
	if(temp < 0) 
	{
		reset();
		for(int count = 0;count < maxval - 1;count++)
			Counter::operator ++();
	}
	return *this;
}

Counter ModCounter::operator --(int)
{
	ModCounter tempcount(*this);
	int temp;
	Counter::operator --();
	temp = getCounterValue();
	if(temp < 0) 
	{
		reset();
		for(int count = 0;count < maxval-1;count++)
			Counter::operator ++();
	}
	return tempcount;
}

bool ModCounter::operator ==(const Counter& other) const
{
		//try to cast to modcounter
		const ModCounter* const otherref = dynamic_cast<const ModCounter* const>(&other);	
		//if not modcounter throw exception
		if(otherref == 0)
			throw Invalid();
		if(maxval == otherref->maxval)
		{
			if(getCounterValue() == other.getCounterValue()) return true;
			else return false;
		}
		else
		{
				throw Invalid();
		}

}
