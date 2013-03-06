#include "User.h"
#include <unistd.h>
#include <iostream.h>

void main()
{
	User obj;

	cout << "Starting run for 60 seconds" << endl;
	obj.run(60);

	sleep(70);

	cout << "Starting run for 60 seconds" << endl;
	obj.run(60);
	sleep(20);
	cout << "Stopping after 20 seconds" << endl;
	obj.stop();
	sleep(70);
}
