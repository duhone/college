// computation2.h : Declaration of the Ccomputation2

#ifndef __COMPUTATION2_H_
#define __COMPUTATION2_H_

#include "resource.h"       // main symbols
#include "cpuid.h"
#include<vector>
/////////////////////////////////////////////////////////////////////////////
// Ccomputation2
class ATL_NO_VTABLE Ccomputation2 : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<Ccomputation2, &CLSID_computation2>,
	public IDispatchImpl<Icomputation2, &IID_Icomputation2, &LIBID_COMP2Lib>
{
public:
	Ccomputation2()
	{
		cpuid();
		problist = new std::vector<double>;
	}

	~Ccomputation2()
	{
		delete problist;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_COMPUTATION2)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(Ccomputation2)
	COM_INTERFACE_ENTRY(Icomputation2)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// Icomputation2
public:
	STDMETHOD(Factorial)(/*[in]*/double dN,/*[out]*/double* dResult);
	STDMETHOD(NCR)(/*[in]*/double dN,/*[in]*/double dR,/*[out]*/double* dResult);
	STDMETHOD(NPR)(/*[in]*/double dN,/*[in]*/double dR,/*[out]*/double* dResult);
	STDMETHOD(StdDev)(/*[out]*/double* dResult);
	STDMETHOD(CalcSum)(/*[out]*/double* dResult);
	STDMETHOD(CalcAvg)(/*[out]*/double* dResult);
	STDMETHOD(AddNumList)(/*[in]*/double arg);
	STDMETHOD(ClearList)();
private:
	std::vector<double> *problist;
};

#endif //__COMPUTATION2_H_
