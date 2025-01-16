﻿// ArithmeticClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <iostream>
#include <atlbase.h>
#include <atlcom.h>
#import "../Arithmetic/x64/Debug/Arithmetic.tlb" no_namespace raw_interfaces_only
#include <fstream>
#include <sstream>
#include <comutil.h>
//#include "../Arithmetic/Arithmetic_i.h"
#include "D:/Work/Andrej71Fs/Src/Arithmetic/Arithmetic/Arithmetic_i.c"

class CArithmeticEvents : //public _IArithmeticEvents //IDispatch
    public CComObjectRootEx<CComSingleThreadModel>,
    public IDispatchImpl<_IArithmeticEvents, &DIID__IArithmeticEvents, &LIBID_ArithmeticLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:

    // IUnknown methods
    STDMETHODIMP QueryInterface(REFIID riid, void** ppvObject)
    {
        if (riid == IID_IUnknown || riid == __uuidof(_IArithmeticEvents))
        {
            *ppvObject = this;
            return S_OK;
        }
        return E_NOINTERFACE;
    }

    STDMETHODIMP_(ULONG) AddRef()
    {
        return InterlockedIncrement(&m_refCount);
    }
    STDMETHODIMP_(ULONG) Release()
    {
        ULONG ulRefCount = InterlockedDecrement(&m_refCount);
        if (0 == ulRefCount) {
            delete this;
        }
        return ulRefCount;
    }

    STDMETHODIMP OnOperation(BSTR operation, DOUBLE a, DOUBLE b, DOUBLE result)
    {
        wprintf(L"Operation: %s, a: %f, b: %f, result: %f\n", operation, a, b, result);
        std::cout << "event!\n";
        return S_OK;
    }

private:
    LONG m_refCount = 1;
};

BSTR ReadXMLFromFile(const wchar_t* filePath)
{
    std::wifstream file(filePath);
    std::wstringstream buffer;
    buffer << file.rdbuf();
    std::wstring content = buffer.str();
    return SysAllocString(content.c_str());
}
int main()
{
    std::cout << "Start!\n";

    CoInitialize(NULL);

    CLSID clsid;
    HRESULT hr = CLSIDFromProgID(L"Exe.OutProc.Arithmetic", &clsid);

    if (SUCCEEDED(hr))
    {
        double result = 0;
        CComPtr<IArithmetic> pArithmetic;
        hr = CoCreateInstance(clsid, NULL, CLSCTX_LOCAL_SERVER, IID_IArithmetic, (void**)&pArithmetic);

        if (SUCCEEDED(hr) && pArithmetic != NULL)
        {
            CArithmeticEvents events;
            CComPtr<IConnectionPointContainer> spCPC;
            CComPtr<IConnectionPoint> spCP;
            DWORD dwCookie;

            hr = pArithmetic->QueryInterface(IID_IConnectionPointContainer, (void**)&spCPC);
            if (SUCCEEDED(hr))
            {
                hr = spCPC->FindConnectionPoint(__uuidof(_IArithmeticEvents), &spCP);
                if (SUCCEEDED(hr))
                {
                    hr = spCP->Advise((IUnknown*)&events, &dwCookie);
                }
            }

            hr = pArithmetic->Add(2, 3, &result);
        }
    }
    else
    {
        std::wcout << L"Failed to get CLSID from ProgID." << std::endl;
    }

    while (true);
    CoUninitialize();
    return 0;
}