#include "ArithmeticEventsSink.h"

class ATL_NO_VTABLE CArithmeticSink :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CArithmeticSink, &CLSID_ArithmeticEventsSink>,
    public IDispEventImpl<1, CArithmeticSink, &DIID__IArithmeticEvents, &LIBID_ArithmeticLib, 1, 0>
{
public:
    CArithmeticSink() {}

    //DECLARE_REGISTRY_RESOURCEID(IDR_ArithmeticSink)

    //BEGIN_COM_MAP(CArithmeticSink)
    //    COM_INTERFACE_ENTRY(_IArithmeticEvents)
    //    COM_INTERFACE_ENTRY(IDispatch)
    //END_COM_MAP()

    BEGIN_SINK_MAP(CArithmeticSink)
        SINK_ENTRY_EX(1, DIID__IArithmeticEvents, 1, OnOperation)
    END_SINK_MAP()

    STDMETHODIMP OnOperation(BSTR operation, DOUBLE a, DOUBLE b, DOUBLE result);
};

// Implement the event handlers
STDMETHODIMP OnOperation(BSTR operation, DOUBLE a, DOUBLE b, DOUBLE result)
{
    wprintf(L"Operation: %s, a: %f, b: %f, result: %f\n", operation, a, b, result);
    std::cout << "event!\n";
    return S_OK;
}

//OBJECT_ENTRY_AUTO(__uuidof(CArithmeticSink), CArithmeticSink)