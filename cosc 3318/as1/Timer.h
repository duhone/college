#ifndef TIMER_H
#define TIMER_H

#include <pthread.h>

// This class implements a Timer which will invoke a function
// either once or periodically until stop is called. To start
// the timer, first create an object of Timer providing the
// function you like to call. Then invoke the start given
// the interval in which to call and mention if you like it to be
// called once or repeatedly. If you started in repeat mode,
// call stop to terminate it. Destroying the Timer object
// will terminate the timer functionality as well.

class Timer
{
public:
	Timer(void(*f)());
	// Purpose: 
	// Requirement: Provide a pointer to function you like to be invoked
	// Promises:
	// Exception:

	virtual ~Timer();
	// Purpose: 
	// Requirement: 
	// Promises: The function will not be called any more. 
	// Exception:

	virtual void start(int seconds, bool repeat);
	// Purpose: Starts the timer functionality to invoke given function.
	// Requirement: seconds must be positive interval, repeat = false says
	// 			function will be called only once.
	// Promises: Function will be called once (repeat=false) after
	//		an interval of given seconds. It may also be called
	//		repeatedly at the interval of given seconds if repeat=
	//		true. If seconds is negative, your request is simply
	//		ignored.
	// Exception:
	
	virtual void stop();
	// Purpose: 
	// Requirement: 
	// Promises: Function will not be called any more.
	// Exception:

private:
	void trigger();
	static void* trigger(void*);

	void (*function)(void);
	bool goOn;
	pthread_t threadID;
	int interval;
};
#endif
