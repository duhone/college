// HARDCOPY of Car.h and Car.cpp due July 16th at 6:10PM in class.
// Remember to put your name and id. Also follow the reccomended 
// commenting style for your code.

// DO NOT MODIFY THIS FILE in any way

#include <iostream.h>
#include "Car.h"

void reportOnCar(const Car& aCar)
{
	int miles;
	int year;

	aCar.getYearAndMiles(year, miles);
	cout << "This car has done " << miles << " miles since " << year << endl;
}

void main()
{
	Car myCar(2000);

	myCar.incrementMiles();
	reportOnCar(myCar);

	myCar.incrementMiles();
	reportOnCar(myCar);

	myCar.incrementMiles();
	reportOnCar(myCar);
}
