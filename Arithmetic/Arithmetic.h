// Arithmetic.h : Declaration of the CArithmetic

#pragma once
#include "resource.h"       // main symbols

#include "Arithmetic_i.h"
#include "_IArithmeticEvents_CP.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;

// CArithmetic

class ATL_NO_VTABLE CArithmetic :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArithmetic, &CLSID_Arithmetic>,
    public IConnectionPointContainerImpl<CArithmetic>,
    public CProxy_IArithmeticEvents<CArithmetic>,
    public IDispatchImpl<IArithmetic, &IID_IArithmetic, &LIBID_ArithmeticLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
    CArithmetic()
    {
    }

    DECLARE_REGISTRY_RESOURCEID(IDR_ARITHMETIC)

    BEGIN_COM_MAP(CArithmetic)
        COM_INTERFACE_ENTRY(IArithmetic)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IConnectionPointContainer)
    END_COM_MAP()

    BEGIN_CONNECTION_POINT_MAP(CArithmetic)
        CONNECTION_POINT_ENTRY(__uuidof(_IArithmeticEvents))
    END_CONNECTION_POINT_MAP()

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    HRESULT FinalConstruct()
    {
        return S_OK;
    }

    void FinalRelease()
    {
    }

    // IArithmetic
public:
    STDMETHOD(Add)(DOUBLE a, DOUBLE b, DOUBLE* result);
    STDMETHOD(Subtract)(DOUBLE a, DOUBLE b, DOUBLE* result);
    STDMETHOD(ProcessXML)(BSTR xmlData);
    STDMETHOD(ProcessXMLFromFile)(BSTR filePath);

private:
    HRESULT InsertIntoDatabase(int id, BSTR name);
    HRESULT ProcessXMLDocument(CComPtr<IXMLDOMDocument> spXMLDoc);
};

OBJECT_ENTRY_AUTO(__uuidof(Arithmetic), CArithmetic)
