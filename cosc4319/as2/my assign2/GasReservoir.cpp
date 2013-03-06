// GasReservoir.cpp : Implementation of CGasReservoir
#include "stdafx.h"
#include "Assign2.h"
#include "GasReservoir.h"

/////////////////////////////////////////////////////////////////////////////
// CGasReservoir


STDMETHODIMP CGasReservoir::drainGas(int grade, double amount)
{
	// TODO: Add your implementation code here
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

STDMETHODIMP CGasReservoir::fillTank(int grade, double amount)
{
	// TODO: Add your implementation code here
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

STDMETHODIMP CGasReservoir::getTankCapacity(int grade, double *pCapacity)
{
	// TODO: Add your implementation code here
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

STDMETHODIMP CGasReservoir::getGasLevel(int grade, double *pLevel)
{
	// TODO: Add your implementation code here
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
