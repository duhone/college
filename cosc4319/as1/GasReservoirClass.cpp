//Name: Eric Duhon
//SSN: 453-97-8531

// GasReservoirClass.cpp: implementation of the GasReservoirClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GasReservoirClass.h"
#include "GasReservoir.h"

extern long locks;
extern void LockModule(void);
extern void UnLockModule(void);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GasReservoirClass::GasReservoirClass()
{

}

GasReservoirClass::~GasReservoirClass()
{

}

STDMETHODIMP GasReservoirClass::CreateInstance(IUnknown *pUnkOuter,REFIID riid,void **ppv)
{

	*ppv = 0;
	if(pUnkOuter != 0)
		return E_FAIL;

//create a new gas tank
	GasReservoir *p = new GasReservoir;
	if(p == 0)
		return E_OUTOFMEMORY;
	p->AddRef();

//get the requested interface
	HRESULT hr = p->QueryInterface(riid,ppv);

	p->Release();

	
	return hr;
}

STDMETHODIMP GasReservoirClass::LockServer(BOOL bLock)
{

	return S_OK;
}

STDMETHODIMP_(ULONG) GasReservoirClass::AddRef(void)
{
	LockModule();
	return 2;
}



STDMETHODIMP_(ULONG) GasReservoirClass::Release(void)
{
	UnLockModule();
	return 1;
}

STDMETHODIMP GasReservoirClass::QueryInterface(REFIID riid,void **ppv)
{
//check for supported interfaces and return the requested one
if(riid == IID_IClassFactory)
	*ppv = static_cast<IClassFactory*>(this);
else if(riid == IID_IUnknown)
	*ppv = static_cast<IClassFactory*>(this);
else
{
//interface was not supported
	*ppv = 0;
	return E_NOINTERFACE;
}

reinterpret_cast<IUnknown*>(*ppv)->AddRef();
return S_OK;

}
