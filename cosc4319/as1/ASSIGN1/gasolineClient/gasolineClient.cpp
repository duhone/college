#include <iostream.h>
#include <stdio.h>
#include "..\gasolineInterfaces\gasolineInterfaces.h"

void printError(HRESULT hr, const char* errorMessage)
{
	char hResultError[100];
	
	::FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0,
		hr, 0, hResultError, 100, 0);

	cout << "Error: " << hResultError;
	cout << errorMessage << endl << endl;
}

int selectGrade()
{
	int sel;
	cout << "Select a Gas grade:\n";
	cout << "0 for regular, 1 for premium, 2 for supreme:";
	cin >> sel;

	if (sel < 0 || sel > 2)
	{
		cout << "Invalid selection... selecting regular\n";
		sel = 0;
	}

	return sel;
}

void drainGas(IGasReservoir* pReservoir)
{
	int grade = selectGrade();

	double amount;
	cout << "Enter amount of Gas requested:";
	cin >> amount;

	HRESULT hr = pReservoir->drainGas(grade, amount);

	if (hr != S_OK)
	{
		cout << "Error draining " << amount << " gallons of Gas" << endl;
	}
}

void checkLevel(IGasReservoir* pReservoir)
{
	IGasFiller* pGasFiller;

	HRESULT hr =
		pReservoir->QueryInterface(IID_IGasFiller, (void**) &pGasFiller);

	if (hr != S_OK)
	{
		char string[100];
		sprintf(string, "Error getting IGasFiller interface");
		printError(hr, string);
	}
	else
	{
		int grade = selectGrade();

		double level;
		HRESULT hr = pGasFiller->getGasLevel(grade, &level);
		pGasFiller->Release();

		if (hr != S_OK)
		{
			cout << "Error getting level\n";
		}
		else
		{
			cout << "Level is " << level << endl;
		}
	}
}

void refill(IGasReservoir* pReservoir)
{
	IGasFiller* pGasFiller;

	HRESULT hr =
		pReservoir->QueryInterface(IID_IGasFiller, (void**) &pGasFiller);

	if (hr != S_OK)
	{
		char string[100];
		sprintf(string, "Error getting IGasFiller interface");
		printError(hr, string);
	}
	else
	{
		int grade = selectGrade();

		double amount;
		cout << "Enter amount of Gas to be refilled:";
		cin >> amount;

		HRESULT hr = pGasFiller->fillTank(grade, amount);
		pGasFiller->Release();

		if (hr != S_OK)
		{
			cout << "Error refilling tank with " << amount << " gallons of Gas" << endl;
		}
	}
}

void main()
{
	::CoInitialize(NULL);

	IGasReservoir* pReservoir = 0;

	CLSID clsid;
	HRESULT hr;
	
	hr = ::CLSIDFromProgID(L"GasolineReservoir.GasolineReservoir.1", &clsid);
	if (FAILED(hr))
	{
		char string[100];
		sprintf(string, "Can't get clsid for GasReservoir.GasReservoir");
		printError(hr, string);
		return;
	}

	hr = ::CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER,
			IID_IGasReservoir, (void**) &pReservoir);

	if (FAILED(hr))
	{
		char string[100];
		sprintf(string, "Error createing COM Object GasReservoir.GasReservoir");
		printError(hr, string);
		return;
	}

	int sel = 0;

	while (sel < 3)
	{
		cout << "Enter 0 to drain Gas\n";
		cout << "      1 to check Level\n";
		cout << "      2 to refill Gas\n";
		cout << "      3 to exit\n";
		cout << "Selection:";

		cin >> sel;

		switch(sel)
		{
		case 0:
			drainGas(pReservoir);
			break;
		case 1:
			checkLevel(pReservoir);
			break;
		case 2:
			refill(pReservoir);
			break;
		case 3:
			break;
		default:
			cout << "Invalid selection\n";
			break;
		}
	}

	pReservoir->Release();

	::CoUninitialize();
}