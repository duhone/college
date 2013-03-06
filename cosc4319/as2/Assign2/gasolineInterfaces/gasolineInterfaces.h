/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Dec 28 17:00:50 1999
 */
/* Compiler settings for C:\Temp\Doc\examplesAndLabs\session03\Lab\solution\gasolineInterfaces\gasolineInterfaces.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
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

#ifndef __gasolineInterfaces_h__
#define __gasolineInterfaces_h__

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


/* header files for imported files */
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IGasReservoir_INTERFACE_DEFINED__
#define __IGasReservoir_INTERFACE_DEFINED__

/* interface IGasReservoir */
/* [uuid][object] */ 


EXTERN_C const IID IID_IGasReservoir;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B6CB97C0-BD47-11d3-87A2-444553540000")
    IGasReservoir : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE drainGas( 
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
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *drainGas )( 
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


#define IGasReservoir_drainGas(This,grade,amount)	\
    (This)->lpVtbl -> drainGas(This,grade,amount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGasReservoir_drainGas_Proxy( 
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
/* [uuid][object] */ 


EXTERN_C const IID IID_IGasFiller;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B6CB97C1-BD47-11d3-87A2-444553540000")
    IGasFiller : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE getGasLevel( 
            /* [in] */ int grade,
            /* [out] */ double __RPC_FAR *pLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getTankCapacity( 
            /* [in] */ int grade,
            /* [out] */ double __RPC_FAR *pCapacity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE fillTank( 
            /* [in] */ int grade,
            /* [in] */ double amount) = 0;
        
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
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getGasLevel )( 
            IGasFiller __RPC_FAR * This,
            /* [in] */ int grade,
            /* [out] */ double __RPC_FAR *pLevel);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getTankCapacity )( 
            IGasFiller __RPC_FAR * This,
            /* [in] */ int grade,
            /* [out] */ double __RPC_FAR *pCapacity);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *fillTank )( 
            IGasFiller __RPC_FAR * This,
            /* [in] */ int grade,
            /* [in] */ double amount);
        
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


#define IGasFiller_getGasLevel(This,grade,pLevel)	\
    (This)->lpVtbl -> getGasLevel(This,grade,pLevel)

#define IGasFiller_getTankCapacity(This,grade,pCapacity)	\
    (This)->lpVtbl -> getTankCapacity(This,grade,pCapacity)

#define IGasFiller_fillTank(This,grade,amount)	\
    (This)->lpVtbl -> fillTank(This,grade,amount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IGasFiller_getGasLevel_Proxy( 
    IGasFiller __RPC_FAR * This,
    /* [in] */ int grade,
    /* [out] */ double __RPC_FAR *pLevel);


void __RPC_STUB IGasFiller_getGasLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGasFiller_getTankCapacity_Proxy( 
    IGasFiller __RPC_FAR * This,
    /* [in] */ int grade,
    /* [out] */ double __RPC_FAR *pCapacity);


void __RPC_STUB IGasFiller_getTankCapacity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IGasFiller_fillTank_Proxy( 
    IGasFiller __RPC_FAR * This,
    /* [in] */ int grade,
    /* [in] */ double amount);


void __RPC_STUB IGasFiller_fillTank_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGasFiller_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
