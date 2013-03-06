//Name: Eric Duhon
//SSN: 453-97-8531

// GasReservoir.cpp: implementation of the GasReservoir class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GasReservoir.h"

extern long locks;
extern void LockModule(void);
extern void UnLockModule(void);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GasReservoir::GasReservoir()
{
	ref_count = 0;
	capacity_reg =1000;
	capacity_prem = 1500;
	capacity_sup = 1000;
	level_reg = 0;
	level_prem = 0;
	level_sup = 0;
}

GasReservoir::~GasReservoir()
{

}

HRESULT STDMETHODCALLTYPE GasReservoir::drainGas(int grade, double amount)
{
	if(amount < 0)
		return S_FALSE;
//drain gas
	switch(grade)
	{
	case 0:
//regular
		if((amount == 0) && (level_reg == 0))
			return S_FALSE;
		if(amount > level_reg)
		{
			return S_FALSE;
		}
		level_reg -= amount;
		break;
	case 1:
//premium
		if((amount == 0) && (level_prem == 0))
			return S_FALSE;
		if(amount > level_prem)
		{
			return S_FALSE;
		}
		level_prem -= amount;
		break;
	case 2:
//supreme
		if((amount == 0) && (level_sup == 0))
			return S_FALSE;
		if(amount > level_sup)
		{
			return S_FALSE;
		}
		level_sup -= amount;
		break;
	default:
//invalid grade
		return S_FALSE;
	};
	return S_OK;
}

HRESULT STDMETHODCALLTYPE GasReservoir::fillTank(int grade, double amount)
{
	if(amount < 0)
		return S_FALSE;
	switch(grade)
	{
	case 0:
//regular
		if((amount+level_reg) > capacity_reg)
		{
			return S_FALSE;
		}
		level_reg += amount;
		break;
	case 1:
//premium
		if((amount+level_prem) > capacity_prem)
		{
			return S_FALSE;
		}
		level_prem += amount;
		break;
	case 2:
//supreme
		if((amount+level_sup) > capacity_sup)
		{
			return S_FALSE;
		}
		level_sup += amount;
		break;
	default:
//invalid grade
		return S_FALSE;
	};
	return S_OK;
}

HRESULT STDMETHODCALLTYPE GasReservoir::getGasLevel(int grade, double *pLevel)
{
	*pLevel = 0;
	switch(grade)
	{
	case 0:
//regular
		*pLevel = level_reg;
		break;
	case 1:
//premium
		*pLevel = level_prem;
		break;
	case 2:
//supreme
		*pLevel = level_sup;
		break;
	default:
//invalid grade
		return S_FALSE;
	};
		return S_OK;
}

HRESULT STDMETHODCALLTYPE GasReservoir::getTankCapacity(int grade, double *pCapacity)
{
	*pCapacity = 0;
	switch(grade)
	{
	case 0:
//regular
		*pCapacity = capacity_reg;
		break;
	case 1:
//premium
		*pCapacity = capacity_prem;
		break;
	case 2:
//supreme
		*pCapacity = capacity_sup;
		break;
	default:
//invalid grade
		return S_FALSE;
	};
	return S_OK;
}

STDMETHODIMP_(ULONG) GasReservoir::AddRef()
{
	if(ref_count == 0) LockModule();
	InterlockedIncrement(&ref_count);
	return ref_count;
}

STDMETHODIMP_(ULONG) GasReservoir::Release()
{
	long res = InterlockedDecrement(&ref_count);
	if(res == 0)
	{
		delete this;
		UnLockModule();
	}
	return res;
}

STDMETHODIMP GasReservoir::QueryInterface(REFIID riid, void **ppv)
{
//return requested interface if available
	if(riid == IID_IGasFiller)
		*ppv = static_cast<IGasFiller*>(this);
	else if(riid == IID_IGasReservoir)
			*ppv = static_cast<IGasReservoir*>(this);
	else if(riid == IID_IUnknown)
		*ppv = static_cast<IGasFiller*>(this);
	else
	{
//requested interface not available
		*ppv = 0;
		return E_NOINTERFACE;
	}

	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return S_OK;

}

