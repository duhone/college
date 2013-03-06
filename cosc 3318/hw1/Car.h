///Name:	Eric Duhon
//Social:	453-97-8531


/*
	The purpose of the Car class is to abstract a simple car. It 
	provides functions to increment the number of miles on the car and to 
	return the number of miles and year model to the user. Objects must be
	created my passing the year model to the object when it is constructed
*/

class Car
{
private:
	int m_imiles;
	int m_iyear;
public:
	Car(const int year);
	void incrementMiles();
		//Purpose: To increment the number of miles on the car
		//Requirement:
		//Promise: will increment the number of miles by one
		//Exception: 
	void getYearAndMiles(int& year,int& miles) const;
		//Purpose: To return to the user the number of miles and the
		//			year model of the car.
		//Requirement: 
		//Promise: will not modify the state of the car
		//Exception: 

};
