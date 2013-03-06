//Name: Eric Duhon
//SSN: 453-97-8531

// GasReservoirClass.h: interface for the GasReservoirClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GASRESERVOIRCLASS_H__D737DCC9_A22E_4FD8_90AE_5E4D2A2F5947__INCLUDED_)
#define AFX_GASRESERVOIRCLASS_H__D737DCC9_A22E_4FD8_90AE_5E4D2A2F5947__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//#include "rpc.h"
//#include "rpcndr.h"
#include "ole2.h"

class GasReservoirClass : public IClassFactory  
{
public:
	GasReservoirClass();
	// Purpose: Construct a class factory object.
    // Requirement: 
    // Promise: will construct a class factory object 
    // Exception:
	virtual ~GasReservoirClass();
	// Purpose: Destruct a class factory object.
    // Requirement: 
    // Promise: will destruct a class factory object 
    // Exception: 
	STDMETHODIMP CreateInstance(IUnknown *pUnkOuter,REFIID riid,void **ppv);
	// Purpose: Create a new com oobject
    // Requirement: pUnkouter must be null, riid must be the desired
	//		interface.
    // Promise: will return an object that implements the requested
	//		interfave in ppv;
    // Exception: 
	STDMETHODIMP LockServer(BOOL bLock);
	// Purpose: Lock the server.
    // Requirement: bLock tells wether to lock or unlock.
    // Promise: used to support aggregation.
    // Exception: 
	STDMETHODIMP_(ULONG) AddRef(void);
	// Purpose: To increment the dll usage count.
    // Requirement: 
    // Promise: Increases the dll usage count to prevent it from being 
	//		unloaded
    // Exception: 
	STDMETHODIMP_(ULONG) Release(void);
	// Purpose: release the classfactory.
    // Requirement: 
    // Promise: decreasses the dll usage count when the user is done
	//		with this class factory.
    // Exception: 
	STDMETHODIMP QueryInterface(REFIID riid,void **ppv);
	// Purpose: Query for a new interface
    // Requirement: riid is the requested interface
    // Promise: will return a pointer to the requested interface. this
	//		factory only supprots the IUnkown and IClassfactory interfaces
    // Exception: 

};

#endif // !defined(AFX_GASRESERVOIRCLASS_H__D737DCC9_A22E_4FD8_90AE_5E4D2A2F5947__INCLUDED_)
