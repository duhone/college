// COSC 4319 HW3 Fall 2001

//NAME:  Eric Duhon
//SSN:   453-97-8531

// Hard copy of one page due in class Wednesday Oct. 24 by 5:45PM.
// The client project directory contains the following files:
// CounterComp.h, CounterComp_i.c, CounterComp.dll. Make sure you
// register this dll before trying the client.

// Convert the following code to use Smart Pointers:
// You must follow the following:
// Do not remove any code, only comment out.
// Add any code you need to. Do not write any additional functions.
// The output must be exactly the same as the current code produces.
// You should use both CComPtr and CComQIPtr.

#include <iostream.h>
#include "CounterComp.h"
#include <atlbase.h> // All you need for use of smart pointer

void main()
{
	::CoInitialize(NULL);

//	CLSID clsid;
//	HRESULT hr;

//	::CLSIDFromProgID(L"CounterComp.Counter.1", &clsid);

//	IUnknown* pUnknown;
	CComPtr<IUnknown> pUnknown;

	cout << "About to get object" << endl;
//	hr = ::CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER, IID_IUnknown,(void**)&pUnknown);
	pUnknown.CoCreateInstance(L"CounterComp.Counter.1");
//	if (hr == S_OK)
	if (pUnknown)
	{
		cout << "Got the object" << endl;

		cout << "Now we will get the counter" << endl;

//		ICounter* pCounter;
//		hr = pUnknown->QueryInterface(IID_ICounter, (void**) &pCounter);
		CComQIPtr<ICounter, &IID_ICounter> pCounter(pUnknown);
//		if (hr == S_OK)
		if (pCounter)
		{
			long val;
			pCounter->getValue(&val);

			cout << "Counter value is " << val << endl;
			pCounter->increment();
			pCounter->getValue(&val);

			cout << "Counter value is " << val << endl;

//			pCounter->Release();
			pCounter.Release();
		}

//		pUnknown->Release();
		pUnknown.Release();
	}


	::CoUninitialize();
}