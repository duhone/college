COSC 4319 DOC - Online copy Due Wednesday 17th by 5:45PM
Instructions for submission will be sent by email.
You need an account on bayou. Call 713-743-1411 if you do not have an
account on bayou.

Write a DLL component (using C++ MI - DO NOT USE ATL) that will represent
a Gas Reservoir. It will support an interface called IGasReservoir
that will support the following functions:

	drainGas 
		will drain the given amount, in gallons, of gas of 
		the given grade.

It will also support another interface called IGasFiller which supports
the following interface:
	getGasLevel
		will return the level, in gallons, of a given grade 
		of gas. The gas grade may be 0 for regular, 1 for
		premium and 2 for supreme. 

	getTankCapacity
		Returns the capacity of the tank for the given grade
		of gas

	fillTank
		Fills the tank, with the given amount of gasoline,
		for the said grade.

Provide the following capacity for the tanks:
Regular: 1000 gallons
Premium: 1500 gallons
Supreme: 1000 gallons

Start with an initial level of gasoline at 0 for each of the grades.

A client program that will test your com object is provided.
I have also provided a sample com object that you can play with to see
if your behaves like mine does.


Things you need to do.

In your DllMain, put the following code

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
	::MessageBox(0, "YOUR NAME", "Gasoline Reservoir", 0);
        GetModuleFileName(hInstance, g_pFileName, MAX_PATH);
    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
    }

    return TRUE;
}

where "YOUR NAME" should be replaced by your actual name.

Use the following prog id for your com object: GasolineReservoir.GasolineReservoir.1


How to test your code and play with my solution as well.

In windows Explorer go to the directory called venkatssolution.
Single click on gasolineReservoir.dll and hold the shift button and right click on it.
Select open with and select choose program. You will get a dialog for Open With. Click 
on other and go to the winnt\system32 directory. You will find regsvr32.exe. Double click on
it. Check the option "Always use this program to open these files". Click OK. From now on,
ow you can double click on a dll to register it.

If you want to test with my code, simply double click on my dll. If you want to test your
code, simply double click on your dll. Run the client to test.
If you have any questions, please let me know.