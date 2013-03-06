// GasReservoir.h : Declaration of the CGasReservoir

#ifndef __GASRESERVOIR_H_
#define __GASRESERVOIR_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGasReservoir
class ATL_NO_VTABLE CGasReservoir : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CGasReservoir, &CLSID_GasReservoir>,
	public IDispatchImpl<IGasReservoir, &IID_IGasReservoir, &LIBID_ASSIGN2Lib>,
	public IDispatchImpl<IGasFiller, &IID_IGasFiller, &LIBID_ASSIGN2Lib>
{
public:
	CGasReservoir()
	{
		capacity_reg =1000;
		capacity_prem = 1500;
		capacity_sup = 1000;
		level_reg = 0;
		level_prem = 0;
		level_sup = 0;

	}

DECLARE_REGISTRY_RESOURCEID(IDR_GASRESERVOIR)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CGasReservoir)
	COM_INTERFACE_ENTRY(IGasReservoir)
//DEL 	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IGasReservoir)
	COM_INTERFACE_ENTRY(IGasFiller)
END_COM_MAP()

// IGasReservoir
public:
	STDMETHOD(getGasLevel)(/*[in]*/int grade,/*[out]*/double *pLevel);
	STDMETHOD(getTankCapacity)(/*[in]*/int grade,/*[out]*/double *pCapacity);
	STDMETHOD(fillTank)(/*[in]*/int grade,/*[in]*/ double amount);
	STDMETHOD(drainGas)(/*[in]*/int grade,/*[in]*/double amount);
private:
	double level_sup;
	double level_prem;
	double level_reg;
	double capacity_sup;
	double capacity_reg;
	double capacity_prem;
// IGasFiller
};

#endif //__GASRESERVOIR_H_
