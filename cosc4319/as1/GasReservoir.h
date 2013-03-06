//Name: Eric Duhon
//SSN: 453-97-8531

// GasReservoir.h: interface for the GasReservoir class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GASRESERVOIR_H__28030A70_AFDF_47D9_8C11_81AEB59CBFE9__INCLUDED_)
#define AFX_GASRESERVOIR_H__28030A70_AFDF_47D9_8C11_81AEB59CBFE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ASSIGN1\GASOLINEINTERFACES\gasolineInterfaces.h"

class GasReservoir : 
	public IGasFiller, 
	public IGasReservoir  
{
public:
	virtual STDMETHODIMP QueryInterface(REFIID riid,void **ppv);
	// Purpose: query for a new interface
    // Requirement: riid is the requested interface
    // Promise: will return the requested interface in ppv if interface
	//		is supported
    // Exception: 
	virtual STDMETHODIMP_(ULONG) Release();
	// Purpose: release the interface
    // Requirement: 
    // Promise: releases the interface. object will destroy itself when
	//		there are no more interfaces bieng used.
    // Exception: 
	STDMETHODIMP_(ULONG) AddRef(void);
	// Purpose: increments the reference count
    // Requirement: 
    // Promise: lets the object know that another interface
	//		is being used
    // Exception: 
	virtual HRESULT STDMETHODCALLTYPE getTankCapacity(int grade,double *pCapacity);
	// Purpose: get the capacity of the requested tank
    // Requirement: grade contains the requested tank
    // Promise: returns the capacity of the requested tank in pCapacity
    // Exception: 
	virtual HRESULT STDMETHODCALLTYPE getGasLevel(int grade,double *pLevel);
	// Purpose: gets the current level of the tank
    // Requirement: grade specifies which tank to get the grade of.
    // Promise: will return the current level of the requested tank in pLevel
    // Exception: 
	virtual HRESULT STDMETHODCALLTYPE fillTank(int grade,double amount);
	// Purpose: fill the tank
    // Requirement: grade is the tank to fill. amount is the amount of gas to
	//		add to the requested tank
    // Promise: adds the amount of gas specified, to the specified tank
    // Exception: 
	virtual HRESULT STDMETHODCALLTYPE drainGas(int grade,double amount);
	// Purpose: removes gas from the tank
    // Requirement: grade specifies the requested tank. amount is the
	//		amount of gas to remove.
    // Promise: will remove the requested amount of gas from the specified
	//		tank
    // Exception: 
	GasReservoir();
	// Purpose: constructs new tanks
    // Requirement: 
    // Promise: regular and supreme tanks have 100 gallons, premium
	//		tank has 1500 gallons capacity.
    // Exception: 
	virtual ~GasReservoir();
	// Purpose: destroys the tanks
    // Requirement: 
    // Promise: all memory for the tanks will be freed
    // Exception: 

private:
	double level_sup;
	double level_prem;
	double level_reg;
	double capacity_prem;
	double capacity_sup;
	double capacity_reg;
	long ref_count;
};

#endif // !defined(AFX_GASRESERVOIR_H__28030A70_AFDF_47D9_8C11_81AEB59CBFE9__INCLUDED_)
