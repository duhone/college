// Do not modify this file.

// Due 6:10PM August 9th

#include "Counter.h"
#include "ModCounter.h"
#include <iostream.h>

void print(const Counter& ctr)
{
	cout << ctr.getCounterValue() << endl;
}

void playWithCounter(Counter& ctr)
{
	ctr++;
	print (ctr);
	ctr++;
	print (ctr);
	ctr++;
	print (ctr);
	ctr++;
	print (ctr);

	ctr--;
	print (ctr);
	ctr--;
	print (ctr);
	ctr--;
	print (ctr);

	ctr.reset();
	print (ctr);
	ctr--;
	print (ctr);
}

void main()
{
	cout << "Working with Counter" << endl;
	Counter ctr;
	playWithCounter (ctr);

	cout << "Working with ModCounter" << endl;
	ModCounter mctr2(2);
	playWithCounter (mctr2);

	cout << "Working with ModCounter" << endl;
	ModCounter mctr3(3);
	playWithCounter (mctr3);


	try
	{
		Counter ctr2;
		if (ctr == ctr2)
			cout << "Same" << endl;
		else
			cout << "Different" << endl;

		ModCounter mc2a(2);
		ModCounter mc2b(2);
		if (mc2a == mc2b)
			cout << "Same" << endl;
		else
			cout << "Different" << endl;
		
		if (mctr3 == ctr2)
			cout << "Same" << endl;
		else
			cout << "Different" << endl;

		if (mctr3 == mc2a)
			cout << "Same" << endl;
		else
			cout << "Different" << endl;
	}
	catch(Invalid e)
	{
		cout << "Exception thrown" << endl;
	}

	try
	{
		cout << "Working with copy Counter" << endl;
		Counter ctr4;
		ctr4++;
		mctr3 = ctr4;
		playWithCounter (mctr3);
	}
	catch(Invalid e)
	{
		cout << "Exception thrown" << endl;
	}
	try
	{
		cout << "Working with copy modCounter" << endl;
		Counter ctr4;
		//ctr4++;
	    mctr3.reset();
		mctr3++;
		ctr4 = mctr3;
		playWithCounter (ctr4);
	}
	catch(Invalid e)
	{
		cout << "Exception thrown" << endl;
	}

}
