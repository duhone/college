//Name: Eric Duhon
//ID: 453-97-8531
#include"Microwave.h"
#include<windows.h>
#include<stdio.h>
#include<iostream.h>

Microwave::Microwave()
{
	status = NULL;
}

Microwave::~Microwave()
{
	if(status != NULL)
		delete[] status;
	
}

void Microwave::add30()
{
	bool iscooking;
	time_t temptime;
	temptime = time(NULL);
	if(difftime(temptime,endtime) >= 0)
		iscooking = false;
	else 
		iscooking = true;
	if(iscooking) 
	{
		endtime += 30;
		timer.start((endtime - temptime),false);
	}
	else
	{
		endtime = temptime + 30;
		timer.start(30,false);
	}

}

bool Microwave::cook(int minutes)
{
	bool iscooking;
	if(minutes <= 0) return false;
	time_t temptime;
	temptime = time(NULL);
	if(difftime(temptime,endtime) >= 0)
		iscooking = false;
	else 
		iscooking = true;
	if(iscooking) return false;
	else
	{
		endtime = temptime + (60*minutes);
		timer.stop();
		timer.start((endtime - temptime),false)
		return true;
	}
}

char* Microwave::getStatus()
{
	bool iscooking;
	time_t temptime;
	temptime = time(NULL);
	if(difftime(temptime,endtime) >= 0)
		iscooking = false;
	else 
		iscooking = true;
	if(iscooking)
	{
		int minutesleft,secondsleft;
		minutesleft = (endtime-temptime)/60;
		secondsleft = (endtime-temptime)%60;
		if(status != NULL)
			delete[] status;
		status = new char[6];
		sprintf(status,"%d:%d",minutesleft,secondsleft);
	}
	else
	{
		tm* fulltime;
		fulltime = localtime(&temptime);
		if(status != NULL)
			delete[] status;
		status = new char[6];
		sprintf(status,"%d:%d",fulltime->tm_hour,fulltime->tm_min);
	}
	return status;
}

void Microwave::stop()
{
	timer.stop();
	time_t temptime;
	temptime = time(NULL);
	endtime = temptime;
}

void Microwave::beep()
{
	cout << "\a";
}