/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Oct 21 23:32:05 2001
 */
/* Compiler settings for C:\cosc4319\as2\my assign2\assign2.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __assign2_h__
#define __assign2_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IGasReservoir_FWD_DEFINED__
#define __IGasReservoir_FWD_DEFINED__
typedef interface IGasReservoir IGasReservoir;
#endif 	/* __IGasReservoir_FWD_DEFINED__ */


#ifndef __IGasFiller_FWD_DEFINED__
#define __IGasFiller_FWD_DEFINED__
typedef interface IGasFiller IGasFiller;
#endif 	/* __IGasFiller_FWD_DEFINED__ */


#ifndef __GasReservoir_FWD_DEFINED__
#define __GasReservoir_FWD_DEFINED__

#ifdef __cplusplus
typedef class GasReservoir GasReservoir;
#else
typedef struct GasReservoir GasReservoir;
#endif /* __cplusplus */

#endif 	/* __GasReservoir_FWD_DEFINED__ */


#ifndef __GasFiller_FWD_DEFINED__
#define __GasFiller_FWD_DEFINED__

#ifdef __cplusplus
typedef class GasFiller GasFiller;
#else
typedef struct GasFiller GasFiller;
#endif /* __cplusplus */

#endif 	/* __GasFiller_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IGasReservoir_INTERFACE_DEFINED__
#define __IGasReservoir_INTERFACE_DEFINED__

/* interface IGasReservoir */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGasReservoir;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F621F82B-39D7-4CD8-A2AD-DF6B70880C84")
    IGasReservoir : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE drainGas( 
            /* [in] */ int grade,
            /* [in] */ double amount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGasReservoirVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGasReservoir __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGasReservoir __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGasReservoir __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IGasReservoir __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IGasReservoir __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IGasReservoir __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IGasReservoir __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *drainGas )( 
            IGasReservoir __RPC_FAR * This,
            /* [in] */ int grade,
            /* [in] */ double amount);
        
        END_INTERFACE
    } IGasReservoirVtbl;

    interface IGasReservoir
    {
        CONST_VTBL struct IGasReservoirVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGasReservoir_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGasReservoir_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGasReservoir_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGasReservoir_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IGasReservoir_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IGasReservoir_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IGasReservoir_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IGasReservoir_drainGas(This,grade,amount)	\
    (This)->lpVtbl -> drainGas(This,grade,amount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGasReservoir_drainGas_Proxy( 
    IGasReservoir __RPC_FAR * This,
    /* [in] */ int grade,
    /* [in] */ double amount);


void __RPC_STUB IGasReservoir_drainGas_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGasReservoir_INTERFACE_DEFINED__ */


#ifndef __IGasFiller_INTERFACE_DEFINED__
#define __IGasFiller_INTERFACE_DEFINED__

/* interface IGasFiller */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGasFiller;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("168BF217-DD5B-4406-8DAB-6731421B0063")
    IGasFiller : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE fillTank( 
            /* [in] */ int grade,
            /* [in] */ double amount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getTankCapacity( 
            /* [in] */ int grade,
            /* [out] */ double __RPC_FAR *pCapacity) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getGasLevel( 
            /* [in] */ int grade,
            /* [out] */ double __RPC_FAR *pLevel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGasFillerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGasFiller __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGasFiller __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGasFiller __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IGasFiller __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IGasFiller __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IGasFiller __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IGasFiller __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *fillTank )( 
            IGasFiller __RPC_FAR * This,
            /* [in] */ int grade,
            /* [in] */ double amount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getTankCapacity )( 
            IGasFiller __RPC_FAR * This,
            /* [in] */ int grade,
            /* [out] */ double __RPC_FAR *pCapacity);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getGasLevel )( 
            IGasFiller __RPC_FAR * This,
            /* [in] */ int grade,
            /* [out] */ double __RPC_FAR *pLevel);
        
        END_INTERFACE
    } IGasFillerVtbl;

    interface IGasFiller
    {
        CONST_VTBL struct IGasFillerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGasFiller_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGasFiller_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGasFiller_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGasFiller_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IGasFiller_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IGasFiller_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IGasFiller_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IGasFiller_fillTank(This,grade,amount)	\
    (This)->lpVtbl -> fillTank(This,grade,amount)

#define IGasFiller_getTankCapacity(This,grade,pCapacity)	\
    (This)->lpVtbl -> getTankCapacity(This,grade,pCapacity)

#define IGasFiller_getGasLevel(This,grade,pLevel)	\
    (This)->lpVtbl -> getGasLevel(This,grade,pLevel)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGasFiller_fillTank_Proxy( 
    IGasFiller __RPC_FAR * This,
    /* [in] */ int grade,
    /* [in] */ double amount);


void __RPC_STUB IGasFiller_fillTank_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGasFiller_getTankCapacity_Proxy( 
    IGasFiller __RPC_FAR * This,
    /* [in] */ int grade,
    /* [out] */ double __RPC_FAR *pCapacity);


void __RPC_STUB IGasFiller_getTankCapacity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGasFiller_getGasLevel_Proxy( 
    IGasFiller __RPC_FAR * This,
    /* [in] */ int grade,
    /* [out] */ double __RPC_FAR *pLevel);


void __RPC_STUB IGasFiller_getGasLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGasFiller_INTERFACE_DEFINED__ */



#ifndef __ASSIGN2Lib_LIBRARY_DEFINED__
#define __ASSIGN2Lib_LIBRARY_DEFINED__

/* library ASSIGN2Lib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ASSIGN2Lib;

EXTERN_C const CLSID CLSID_GasReservoir;

#ifdef __cplusplus

class DECLSPEC_UUID("8628F9C5-2B0C-400F-BE78-5B1482E7736D")
GasReservoir;
#endif

EXTERN_C const CLSID CLSID_GasFiller;

#ifdef __cplusplus

class DECLSPEC_UUID("C2BF3D02-DE1B-41EC-AB8B-3A21E4BC4697")
GasFiller;
#endif
#endif /* __ASSIGN2Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
