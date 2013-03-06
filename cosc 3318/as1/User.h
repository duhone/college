#include <Timer.h>

class User
{
public:
	User();
	~User();

	void run(int seconds);
	// Will beep after said seconds.

	void stop();
	// Cancels the beeping request.
private:
	static void beep();
	Timer* pTimer;
};
