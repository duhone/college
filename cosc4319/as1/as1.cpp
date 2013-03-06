//Name: Eric Duhon
//SSN: 453-97-8531

// as1.cpp : Defines the entry point for the DLL application.
//

#include<windows.h>
#include "GasReservoirClass.h"

char g_pFileName[MAX_PATH];


const CLSID CLSID_GasReservoir = { 0xcf8aed0f, 0x8273, 0x4a50, { 0x8d, 0x56, 0xb, 0x1c, 0xdd, 0xd8, 0x61, 0x6e }};

//table to hold registry entries
const char *g_RegTable[][3] = 
{
	{"CLSID\\{CF8AED0F-8273-4a50-8D56-0B1CDDD8616E}",0,"GasolineReservoir"},
	{"CLSID\\{CF8AED0F-8273-4a50-8D56-0B1CDDD8616E}\\InprocServer32",0,(const char*)-1},
	{"CLSID\\{CF8AED0F-8273-4a50-8D56-0B1CDDD8616E}\\ProgID",0,"GasolineReservoir.GasolineReservoir.1"},
	{"GasolineReservoir.GasolineReservoir.1",0,"GasolineReservoir"},
	{"GasolineReservoir.GasolineReservoir.1\\CLSID",0,"{CF8AED0F-8273-4a50-8D56-0B1CDDD8616E}"},

};

long locks = 0;
void LockModule(void) {InterlockedIncrement(&locks);}
void UnLockModule(void) {InterlockedDecrement(&locks);}

extern "C"
BOOL WINAPI DllMain( HINSTANCE hInstance, 
                       DWORD  dwReason, 
                       LPVOID lpReserved
					 )
{
	if (dwReason == DLL_PROCESS_ATTACH)
    {
	::MessageBox(0, "Eric Duhon", "Gasoline Reservoir", 0);
        GetModuleFileName(hInstance, g_pFileName, MAX_PATH);
    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
    }

    return TRUE;
}


STDAPI DllCanUnloadNow()
//decides if the dll can be unloaded from memory
{
	if(locks == 0) return S_OK;
	else return S_FALSE;
}

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
//get a class factory to make the requested class.
{
	static GasReservoirClass ressingleton;
	
	if(rclsid == CLSID_GasReservoir)
		return ressingleton.QueryInterface(riid,ppv);

	*ppv = 0;
	return E_NOINTERFACE;
}


STDAPI DllUnregisterServer(void)
//unregister the server
{
	HRESULT hr = S_OK;
	int nEntries = sizeof(g_RegTable)/sizeof(*g_RegTable);
	for(int i = nEntries-1;i>=0;i--)
	{
		const char *key_name = g_RegTable[i][0];
//delete the keys from resgistry
		long err = RegDeleteKeyA(HKEY_CLASSES_ROOT,key_name);
		if(err != ERROR_SUCCESS)
			hr = S_FALSE;
	}
	return hr;


}

STDAPI DllRegisterServer(void)
//register the server
{
	HRESULT hr = S_OK;

	int nEntries = sizeof(g_RegTable)/sizeof(*g_RegTable);
	for(int i = 0;SUCCEEDED(hr) && i < nEntries; i++)
	{
		const char *key_name = g_RegTable[i][0];
		const char *value_name = g_RegTable[i][1];
		const char *value = g_RegTable[i][2];
		if(value == (const char*)-1)
			value = g_pFileName;
		
		HKEY hkey;
//create the key
		long err = RegCreateKeyA(HKEY_CLASSES_ROOT,key_name,&hkey);
		if(err == ERROR_SUCCESS)
//if the key was created add the values
		{
			err = RegSetValueExA(hkey,value_name,0,REG_SZ,
							(const BYTE*)value,(strlen(value) + 1));
			RegCloseKey(hkey);
		}
		if(err != ERROR_SUCCESS)
//if key was not created return error
		{
			DllUnregisterServer();
			hr = S_FALSE;
		}

	}
	return hr;
}
