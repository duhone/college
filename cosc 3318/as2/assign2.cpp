// DUE Thursday 2nd August at 6:10PM.
// Electronic copy due

// DO NOT MODIFY THIS FILE

#include <iostream.h>
#include "String.h"

void checkString(String obj)
{
	cout << "Given String is ";
	if (!obj)
		cout << "empty\n";
	else
		cout << " not empty\n";
}

void printString(const String& stringObj)
{
	cout << stringObj << endl;

	try
	{
		cout << "First char in the string is " << stringObj[0] << endl;
	}
	catch(OutOfRange& exceptionObj)
	{
		cout << exceptionObj.getError() << endl;
	}

	try
	{
		cout << "20th char in the string is " 
			<< stringObj[19] << endl;
	}
	catch(OutOfRange& exceptionObj)
	{
		cout << exceptionObj.getError() << endl;
	}
}

void main()
{
	const String hello = "Hello!";

	String greet = hello + " there ";

	printString(greet);

	cout << "Now you may create your own string:\n";

	String myString;

	cin >> myString;

	cout << "You entered:";
	printString(myString);

	String bigString = greet + myString;

	printString(bigString);

	try
	{
		greet[1] = 'i';
	}
	catch(OutOfRange& exceptionObj)
	{
		cout << exceptionObj.getError() << endl;
	}

	printString(greet);
	checkString(greet);

	String eString;
	checkString(eString);
}
