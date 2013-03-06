//Name: Eric Duhon
//ID: 453-97-8531


/*
	The purpose of the Microwave class is to abstract a simple Microwave. It 
	provides functions to interact with the microwave. The microwave will
	beep when it is finished.
*/


#include<time.h>
#include"Timer.h"

class Microwave
{
public:
	Microwave();
	~Microwave();
	bool cook(int minutes);
		//Purpose: To start the microwave cooking
		//Requirement: a poitive number of minutes must be passed in
		//Promise: if minutes are valid and microwave is not currently 
		//		cooking then microwave will cook for specified minutes
		//		and then beep when done.
		//Exception: 
	void add30();
		//Purpose: To 30 additional seconds to microwave count
		//Requirement:
		//Promise: will add 30 seconds to current microwave count or
		//		will start a new 30 second count if microwave is not 
		//		already cooking.
		//Exception: 
	char* getStatus();
		//Purpose: To get the current time on the microwave
		//Requirement:
		//Promise: will return the number of minutes and seconds left
		//		to finish cooking or if not cooking will return the current
		//		time.
		//Exception: 
	void stop();
		//Purpose: To stop the microwave
		//Requirement:
		//Promise: will stop the microwave
		//Exception: 
	void beep();
		//Purpose: Used by timer to beep
		//Requirement:
		//Promise: will beep when called
		//Exception: 
		
private:
	char* status;
	time_t endtime;
	Timer timer(beep);
};