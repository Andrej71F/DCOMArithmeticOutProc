

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for Arithmetic.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0628 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Arithmetic_i_h__
#define __Arithmetic_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IArithmetic_FWD_DEFINED__
#define __IArithmetic_FWD_DEFINED__
typedef interface IArithmetic IArithmetic;

#endif 	/* __IArithmetic_FWD_DEFINED__ */


#ifndef ___IArithmeticEvents_FWD_DEFINED__
#define ___IArithmeticEvents_FWD_DEFINED__
typedef interface _IArithmeticEvents _IArithmeticEvents;

#endif 	/* ___IArithmeticEvents_FWD_DEFINED__ */


#ifndef __Arithmetic_FWD_DEFINED__
#define __Arithmetic_FWD_DEFINED__

#ifdef __cplusplus
typedef class Arithmetic Arithmetic;
#else
typedef struct Arithmetic Arithmetic;
#endif /* __cplusplus */

#endif 	/* __Arithmetic_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IArithmetic_INTERFACE_DEFINED__
#define __IArithmetic_INTERFACE_DEFINED__

/* interface IArithmetic */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IArithmetic;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("27A2F3BE-7420-45D8-9C8E-76BDAA2B92CC")
    IArithmetic : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ DOUBLE a,
            /* [in] */ DOUBLE b,
            /* [retval][out] */ DOUBLE *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Subtract( 
            /* [in] */ DOUBLE a,
            /* [in] */ DOUBLE b,
            /* [retval][out] */ DOUBLE *result) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ProcessXML( 
            /* [in] */ BSTR xmlData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ProcessXMLFromFile( 
            /* [in] */ BSTR filePath) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IArithmeticVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IArithmetic * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IArithmetic * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IArithmetic * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IArithmetic * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IArithmetic * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IArithmetic * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IArithmetic * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IArithmetic, Add)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IArithmetic * This,
            /* [in] */ DOUBLE a,
            /* [in] */ DOUBLE b,
            /* [retval][out] */ DOUBLE *result);
        
        DECLSPEC_XFGVIRT(IArithmetic, Subtract)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Subtract )( 
            IArithmetic * This,
            /* [in] */ DOUBLE a,
            /* [in] */ DOUBLE b,
            /* [retval][out] */ DOUBLE *result);
        
        DECLSPEC_XFGVIRT(IArithmetic, ProcessXML)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ProcessXML )( 
            IArithmetic * This,
            /* [in] */ BSTR xmlData);
        
        DECLSPEC_XFGVIRT(IArithmetic, ProcessXMLFromFile)
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ProcessXMLFromFile )( 
            IArithmetic * This,
            /* [in] */ BSTR filePath);
        
        END_INTERFACE
    } IArithmeticVtbl;

    interface IArithmetic
    {
        CONST_VTBL struct IArithmeticVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IArithmetic_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IArithmetic_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IArithmetic_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IArithmetic_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IArithmetic_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IArithmetic_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IArithmetic_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IArithmetic_Add(This,a,b,result)	\
    ( (This)->lpVtbl -> Add(This,a,b,result) ) 

#define IArithmetic_Subtract(This,a,b,result)	\
    ( (This)->lpVtbl -> Subtract(This,a,b,result) ) 

#define IArithmetic_ProcessXML(This,xmlData)	\
    ( (This)->lpVtbl -> ProcessXML(This,xmlData) ) 

#define IArithmetic_ProcessXMLFromFile(This,filePath)	\
    ( (This)->lpVtbl -> ProcessXMLFromFile(This,filePath) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IArithmetic_INTERFACE_DEFINED__ */



#ifndef __ArithmeticLib_LIBRARY_DEFINED__
#define __ArithmeticLib_LIBRARY_DEFINED__

/* library ArithmeticLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ArithmeticLib;

#ifndef ___IArithmeticEvents_DISPINTERFACE_DEFINED__
#define ___IArithmeticEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IArithmeticEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__IArithmeticEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("840e05c8-9263-41db-8427-a978745b20fa")
    _IArithmeticEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IArithmeticEventsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IArithmeticEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IArithmeticEvents * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IArithmeticEvents * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IArithmeticEvents * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IArithmeticEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IArithmeticEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IArithmeticEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _IArithmeticEventsVtbl;

    interface _IArithmeticEvents
    {
        CONST_VTBL struct _IArithmeticEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IArithmeticEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IArithmeticEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IArithmeticEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IArithmeticEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IArithmeticEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IArithmeticEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IArithmeticEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IArithmeticEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Arithmetic;

#ifdef __cplusplus

class DECLSPEC_UUID("24d8676a-8e19-428e-a2cc-db9fd841c9c1")
Arithmetic;
#endif
#endif /* __ArithmeticLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


