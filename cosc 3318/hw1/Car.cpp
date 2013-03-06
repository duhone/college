#include "car.h"


Car::Car(const int year)
{
	m_iyear = year;
	m_imiles = 0;
}

void Car::incrementMiles()
{
	m_imiles += 1;
}

void Car::getYearAndMiles(int& year,int& miles) const
{
	year = m_iyear;
	miles = m_imiles;
}





