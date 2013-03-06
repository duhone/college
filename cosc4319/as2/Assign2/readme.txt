COSC 4319 DOC - Online copy Due Wednesday 31st Oct. by 5:45PM
Instructions for submission will be sent by email.

Write a Dll component using ATL that will represent the Gas Reservoir discussed in assignment 1.
The differences are:

	drainGas 
		It must take one second to drain 1 gallon of gas

	fillTank
		It must taken one second to fill 5 gallons of gas

Things you need to do.

In your DllMain, put the following code

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
	::MessageBox(0, "YOUR NAME", "Gasoline Reservoir using ATL", 0);
        _Module.Init(ObjectMap, hInstance, &LIBID_GASOLINERESERVOIRCOMPLib);
        DisableThreadLibraryCalls(hInstance);
    }
    else if (dwReason == DLL_PROCESS_DETACH)
        _Module.Term();
    return TRUE;    // ok
}

where "YOUR NAME" should be replaced by your actual name.

Use the following prog id for your com object: GasolineReservoir.GasolineReservoir.1

How to test your code and play with my solution as well.

In windows Explorer go to the directory called venkatssolution.
Single click on gasolineReservoir.dll and hold the shift button and right click on it.
Select open with and select choose program. You will get a dialog for Open With. Click 
on other and go to the winnt\system32 directory. You will find regsvr32.exe. Double click on
it. Check the option "Always use this program to open these files". Click OK. From now on,
you can double click on a dll to register it.

If you want to test with my code, simply double click on my dll. If you want to test your
code, simply double click on your dll. Run the client to test.
If you have any questions, please let me know.