// Electronic submission (not through email) is due 
// July 25th by 6:10PM.
// Remember to put your name and id in the code. Also follow the 
// commenting style for your code.

// Please note this file is just a sample usage of your class. The
// code you write must be based on specifications given below and not
// just the sample code that follows:

// Specification:
/*
	Write a class named Microwave that has the following functionality:

	cook: Takes an integer of number of minutes to cook.
		This method will return a false if the number of minutes is
			invalid or if the Microwave is already busy cooking
				(from a previous call to cook).
				When the cooking is done (or interrupted),
				it will beep.

	add30: This will add 30 seconds to the cook time, if cook has been
		called and the Microwave is busy cooking. If cook has not
		already been called, this will have the effect of calling cook
		for half minute (even though others can't really call cook(0.5).

	getStatus: Returns either of the following messages -
		Current time in the format hh:mm AM if the microwave is not
		being used (not-busy).
		Time left to complete cooking, in the format mm:ss, if it is 
		in use (busy).

	stop:	Will stop the Microwave and put it in not-busy state.
*/

// I will let you think about this and play with it for a day or so. After that,
// I may give you some supporting classes or coding hints by email.

// DO NOT MODIFY THIS FILE in any way


#include <iostream.h>
#include <unistd.h>
#include "Microwave.h"

void main()
{

	Microwave mw;
	cout << mw.getStatus() << endl;

	cout << "Starting microwave:";
	cout << mw.cook(3) << endl;
	cout << mw.getStatus() << endl;

	// sleep for 1 minute
	sleep(60);
	cout << mw.getStatus() << endl;

	// sleep for 1 minute
	sleep(60);
	cout << mw.getStatus() << endl;

	mw.add30();
	cout << mw.getStatus() << endl;

	cout << "Starting microwave:";
	cout << mw.cook(10) << endl;

	// sleep for 3 minutes
	sleep(180);
	cout << mw.getStatus() << endl;
}
