// GasFiller.h : Declaration of the CGasFiller

#ifndef __GASFILLER_H_
#define __GASFILLER_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGasFiller
class ATL_NO_VTABLE CGasFiller : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CGasFiller, &CLSID_GasFiller>,
	public IDispatchImpl<IGasFiller, &IID_IGasFiller, &LIBID_ASSIGN2Lib>
{
public:
	CGasFiller()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_GASFILLER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CGasFiller)
	COM_INTERFACE_ENTRY(IGasFiller)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IGasFiller
public:
	STDMETHOD(getGasLevel)(/*[in]*/int grade,/*[out]*/double *pLevel);
	STDMETHOD(getTankCapacity)(/*[in]*/int grade,/*[out]*/double *pCapacity);
	STDMETHOD(fillTank)(/*[in]*/int grade,/*[in]*/ double amount);
};

#endif //__GASFILLER_H_
