/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Oct 06 20:47:30 2001
 */
/* Compiler settings for C:\cosc4319\calculator\comp2.idl:
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

#ifndef __comp2_h__
#define __comp2_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __Icomputation2_FWD_DEFINED__
#define __Icomputation2_FWD_DEFINED__
typedef interface Icomputation2 Icomputation2;
#endif 	/* __Icomputation2_FWD_DEFINED__ */


#ifndef __computation2_FWD_DEFINED__
#define __computation2_FWD_DEFINED__

#ifdef __cplusplus
typedef class computation2 computation2;
#else
typedef struct computation2 computation2;
#endif /* __cplusplus */

#endif 	/* __computation2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __Icomputation2_INTERFACE_DEFINED__
#define __Icomputation2_INTERFACE_DEFINED__

/* interface Icomputation2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_Icomputation2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96CCE1ED-8884-48C7-A128-770A5A0FB178")
    Icomputation2 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearList( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddNumList( 
            /* [in] */ double arg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CalcAvg( 
            /* [out] */ double __RPC_FAR *dResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CalcSum( 
            /* [out] */ double __RPC_FAR *dResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StdDev( 
            /* [out] */ double __RPC_FAR *dResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NPR( 
            /* [in] */ double dN,
            /* [in] */ double dR,
            /* [out] */ double __RPC_FAR *dResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NCR( 
            /* [in] */ double dN,
            /* [in] */ double dR,
            /* [out] */ double __RPC_FAR *dResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Factorial( 
            /* [in] */ double dN,
            /* [out] */ double __RPC_FAR *dResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct Icomputation2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            Icomputation2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            Icomputation2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            Icomputation2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            Icomputation2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            Icomputation2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            Icomputation2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            Icomputation2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearList )( 
            Icomputation2 __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddNumList )( 
            Icomputation2 __RPC_FAR * This,
            /* [in] */ double arg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CalcAvg )( 
            Icomputation2 __RPC_FAR * This,
            /* [out] */ double __RPC_FAR *dResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CalcSum )( 
            Icomputation2 __RPC_FAR * This,
            /* [out] */ double __RPC_FAR *dResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StdDev )( 
            Icomputation2 __RPC_FAR * This,
            /* [out] */ double __RPC_FAR *dResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NPR )( 
            Icomputation2 __RPC_FAR * This,
            /* [in] */ double dN,
            /* [in] */ double dR,
            /* [out] */ double __RPC_FAR *dResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NCR )( 
            Icomputation2 __RPC_FAR * This,
            /* [in] */ double dN,
            /* [in] */ double dR,
            /* [out] */ double __RPC_FAR *dResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Factorial )( 
            Icomputation2 __RPC_FAR * This,
            /* [in] */ double dN,
            /* [out] */ double __RPC_FAR *dResult);
        
        END_INTERFACE
    } Icomputation2Vtbl;

    interface Icomputation2
    {
        CONST_VTBL struct Icomputation2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Icomputation2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define Icomputation2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define Icomputation2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define Icomputation2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define Icomputation2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define Icomputation2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define Icomputation2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define Icomputation2_ClearList(This)	\
    (This)->lpVtbl -> ClearList(This)

#define Icomputation2_AddNumList(This,arg)	\
    (This)->lpVtbl -> AddNumList(This,arg)

#define Icomputation2_CalcAvg(This,dResult)	\
    (This)->lpVtbl -> CalcAvg(This,dResult)

#define Icomputation2_CalcSum(This,dResult)	\
    (This)->lpVtbl -> CalcSum(This,dResult)

#define Icomputation2_StdDev(This,dResult)	\
    (This)->lpVtbl -> StdDev(This,dResult)

#define Icomputation2_NPR(This,dN,dR,dResult)	\
    (This)->lpVtbl -> NPR(This,dN,dR,dResult)

#define Icomputation2_NCR(This,dN,dR,dResult)	\
    (This)->lpVtbl -> NCR(This,dN,dR,dResult)

#define Icomputation2_Factorial(This,dN,dResult)	\
    (This)->lpVtbl -> Factorial(This,dN,dResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Icomputation2_ClearList_Proxy( 
    Icomputation2 __RPC_FAR * This);


void __RPC_STUB Icomputation2_ClearList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Icomputation2_AddNumList_Proxy( 
    Icomputation2 __RPC_FAR * This,
    /* [in] */ double arg);


void __RPC_STUB Icomputation2_AddNumList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Icomputation2_CalcAvg_Proxy( 
    Icomputation2 __RPC_FAR * This,
    /* [out] */ double __RPC_FAR *dResult);


void __RPC_STUB Icomputation2_CalcAvg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Icomputation2_CalcSum_Proxy( 
    Icomputation2 __RPC_FAR * This,
    /* [out] */ double __RPC_FAR *dResult);


void __RPC_STUB Icomputation2_CalcSum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Icomputation2_StdDev_Proxy( 
    Icomputation2 __RPC_FAR * This,
    /* [out] */ double __RPC_FAR *dResult);


void __RPC_STUB Icomputation2_StdDev_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Icomputation2_NPR_Proxy( 
    Icomputation2 __RPC_FAR * This,
    /* [in] */ double dN,
    /* [in] */ double dR,
    /* [out] */ double __RPC_FAR *dResult);


void __RPC_STUB Icomputation2_NPR_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Icomputation2_NCR_Proxy( 
    Icomputation2 __RPC_FAR * This,
    /* [in] */ double dN,
    /* [in] */ double dR,
    /* [out] */ double __RPC_FAR *dResult);


void __RPC_STUB Icomputation2_NCR_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Icomputation2_Factorial_Proxy( 
    Icomputation2 __RPC_FAR * This,
    /* [in] */ double dN,
    /* [out] */ double __RPC_FAR *dResult);


void __RPC_STUB Icomputation2_Factorial_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __Icomputation2_INTERFACE_DEFINED__ */



#ifndef __COMP2Lib_LIBRARY_DEFINED__
#define __COMP2Lib_LIBRARY_DEFINED__

/* library COMP2Lib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_COMP2Lib;

EXTERN_C const CLSID CLSID_computation2;

#ifdef __cplusplus

class DECLSPEC_UUID("03A6F446-ADE0-4315-8F16-CF28C865F3ED")
computation2;
#endif
#endif /* __COMP2Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
