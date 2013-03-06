#include "User.h"
#include <iostream.h>

User::User()
{
	pTimer = 0;
}

User::~User()
{
	if (pTimer != NULL)
		delete pTimer;
}

void User::run(int seconds)
{
	if (pTimer != NULL)
	{
		delete pTimer;
	}

	pTimer = new Timer(User::beep);
	pTimer->start(seconds, false);
}

void User::stop()
{
	if (pTimer != NULL)
	{
		delete pTimer;
		pTimer = NULL;
	}
}

void User::beep()
{
	cout << "beeping\a";
	cout.flush();
}
