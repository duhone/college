// DO NOT MODIFY THIS FILE

// COSC 3318 Summer 2001
// Assignment 4.
// Due by 6:15PM on Wednesday Ausugst 15th.

// Write a class named PairValue which represents a pair of 
// elements (values or objects). It maintains a copy of two
// elements provided during construction.

// The only way to create an object of PairValue is by providing
// two elements.

// The PairValue class also provide methods to perform the following
// operations:

// To add, subtract value pairs to create another PairValue object.
// To get a member of the pair, and to set a member of the pair.

// Things to follow:

// 1. Follow the coding standard and commenting style.

#include <iostream.h>
#include "PairValue.h"
#include "OutOfIndex.h"
#include "Counter.h"

// Purpose: Prints the given object to the standard output.
template <class T>
void print(const PairValue<T>& pairObj)
{
	cout << "The pair of values is (" <<
		pairObj[0] << ", " << pairObj[1] << ")\n";
}

void main()
{
	try
	{
		PairValue<double> object(2.2, 3);

		print(object);

		PairValue<double> obj2(0, 0);
		double value;
		cout << "Enter a pair of values separated by space:";
		cin >> value;
		obj2[0] = value;
		cin >> value;
		obj2[1] = value;

		print(obj2);

		PairValue<double> sum = object + obj2;
		print(sum);

		print(object - obj2);

		//cout << "Value at index 4 is " << object[4] << endl;
        cout << "Value at index 4 is:" << endl;
        cout << object[4] << endl; 
	}
	catch(OutOfIndex& exception)
	{
		cout << "Exception occurred:" << exception << endl;
	}

	Counter ctr1(1);
	Counter ctr2(2);

	try
	{
		PairValue<Counter> object(ctr1, ctr2);

		print(object);

		PairValue<Counter> obj2(0, 0);
		obj2[0] = Counter(3);
		obj2[1] = Counter(4);

		print(obj2);

		PairValue<Counter> sum = object + obj2;
		print(sum);

		print(object - obj2);

		//cout << "Value at index 4 is " << object[4] << endl;
        cout << "Value at index 4 is:" << endl;
        cout << object[4] << endl; 
	}
	catch(OutOfIndex& exception)
	{
		cout << "Exception occurred:" << exception << endl;
	}
}

