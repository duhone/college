// computation2.cpp : Implementation of Ccomputation2
#include "stdafx.h"
#include "Comp2.h"
#include "computation2.h"
#include<math.h>
//#include "cpuid.h"

/////////////////////////////////////////////////////////////////////////////
// Ccomputation2


STDMETHODIMP Ccomputation2::ClearList()
{
	// TODO: Add your implementation code here
	problist->resize(0);
	return S_OK;
}

STDMETHODIMP Ccomputation2::AddNumList(double arg)
{
	// TODO: Add your implementation code here

	problist->push_back(arg);
	return S_OK;
}

STDMETHODIMP Ccomputation2::CalcAvg(double* dResult)
{
	// TODO: Add your implementation code here
	CalcSum(dResult);
	(*dResult) /= problist->size();
	return S_OK;
}

STDMETHODIMP Ccomputation2::CalcSum(double* dResult)
{
	// TODO: Add your implementation code here
	double retval;
	retval = 0.0;
	int count;
	for(count = 0;count < problist->size();count++)
	{
		retval = retval + (*problist)[count];
	}
	*dResult = retval;

	return S_OK;
}

STDMETHODIMP Ccomputation2::StdDev(double* dResult)
{
	// TODO: Add your implementation code here
	double mean;
	CalcAvg(&mean);
	double sum = 0;
	int count;
	for(count = 0;count < problist->size();count++)
	{
		sum +=  ((*problist)[count] - mean) * ((*problist)[count] - mean);
	}
	sum = sum*(1.0/(problist->size() - 1));
	*dResult = sqrt(sum);


	return S_OK;
}

STDMETHODIMP Ccomputation2::NPR(double dN, double dR, double* dResult)
{
	// TODO: Add your implementation code here
	if(dN > 170.0) return S_FALSE;
	double whole,frac;
	frac = modf(dN,&whole);

	if((frac <.99) && (frac >.01))   return S_FALSE;
	
	double nfac,nmrfac;
	Factorial(dN,&nfac);
	Factorial((dN-dR),&nmrfac);
	*dResult = (nfac/nmrfac);


	return S_OK;
}

STDMETHODIMP Ccomputation2::NCR(double dN, double dR, double* dResult)
{
	// TODO: Add your implementation code here
	if(dN > 170.0) return S_FALSE;
	double whole,frac;
	frac = modf(dN,&whole);

	if((frac <.99) && (frac >.01))   return S_FALSE;

	double nfac,nmrfac,rfac;
	Factorial(dN,&nfac);
	Factorial((dN-dR),&nmrfac);
	Factorial(dR,&rfac);
	*dResult = (nfac/(nmrfac*rfac));

	return S_OK;
}

STDMETHODIMP Ccomputation2::Factorial(double dN, double* dResult)
{
	if(dN > 170.0) return S_FALSE;
	double whole,frac;
	frac = modf(dN,&whole);

	if((frac <.99) && (frac >.01))   return S_FALSE;
	int numcount = (int)whole;
	double dcounter = 2.0;
	*dResult = 1.0;
	for(int count = 2;count <= numcount;count++)
	{
		*dResult *= dcounter;
		dcounter += 1.0;
	}

	return S_OK;
}

