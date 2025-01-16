// Arithmetic.cpp : Implementation of WinMain

#include "pch.h"
#include "Arithmetic.h"

#include "framework.h"
#include "resource.h"
#include "Arithmetic_i.h"
#include "xdlldata.h"
#include <fstream>
#include <comutil.h>
#include <atldbcli.h>
#include "_IArithmeticEvents_CP.h"
#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>
#include <msxml6.h>
#include <string>

using namespace ATL;

class CArithmeticModule : public ATL::CAtlExeModuleT< CArithmeticModule >
{
public:
    DECLARE_LIBID(LIBID_ArithmeticLib)
    DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ARITHMETIC, "{24d8676a-8e19-428e-a2cc-db9fd841c9c1}")
};

CArithmeticModule _AtlModule;

//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/,
    LPTSTR /*lpCmdLine*/, int nShowCmd)
{
    return _AtlModule.WinMain(nShowCmd);
}

STDMETHODIMP CArithmetic::Add(DOUBLE a, DOUBLE b, DOUBLE* result)
{
    *result = a + b;
    CComBSTR operation = L"Add";
    Fire_OnOperation(operation, a, b, *result);
    return S_OK;
}

STDMETHODIMP CArithmetic::Subtract(DOUBLE a, DOUBLE b, DOUBLE* result)
{
    *result = a - b;
    CComBSTR operation = L"Subtract";
    Fire_OnOperation(operation, a, b, *result);
    return S_OK;
}

STDMETHODIMP CArithmetic::ProcessXML(BSTR xmlData)
{
    CComPtr<IXMLDOMDocument> spXMLDoc;
    HRESULT hr = spXMLDoc.CoCreateInstance(__uuidof(DOMDocument60));
    if (FAILED(hr)) return hr;

    VARIANT_BOOL loadSuccess;
    hr = spXMLDoc->loadXML(xmlData, &loadSuccess);
    if (FAILED(hr) || loadSuccess == VARIANT_FALSE) return E_FAIL;

    return ProcessXMLDocument(spXMLDoc);
}

STDMETHODIMP CArithmetic::ProcessXMLFromFile(BSTR filePath)
{
    CComPtr<IXMLDOMDocument> spXMLDoc;
    HRESULT hr = spXMLDoc.CoCreateInstance(__uuidof(DOMDocument60));
    if (FAILED(hr)) return hr;

    VARIANT_BOOL loadSuccess;
    //hr = spXMLDoc->load(filePath, &loadSuccess);
    //if (FAILED(hr) || loadSuccess == VARIANT_FALSE) return E_FAIL;

    return ProcessXMLDocument(spXMLDoc);
}

HRESULT CArithmetic::ProcessXMLDocument(CComPtr<IXMLDOMDocument> spXMLDoc)
{
    CComPtr<IXMLDOMNodeList> spNodes;
    HRESULT hr = spXMLDoc->selectNodes(CComBSTR(L"/data/item"), &spNodes);
    if (FAILED(hr)) return hr;

    long length;
    spNodes->get_length(&length);

    for (long i = 0; i < length; ++i)
    {
        CComPtr<IXMLDOMNode> spNode;
        spNodes->get_item(i, &spNode);

        CComPtr<IXMLDOMNode> spIDNode;
        CComPtr<IXMLDOMNode> spNameNode;
        spNode->selectSingleNode(CComBSTR(L"id"), &spIDNode);
        spNode->selectSingleNode(CComBSTR(L"name"), &spNameNode);

        if (spIDNode && spNameNode)
        {
            CComBSTR bstrID;
            CComBSTR bstrName;
            spIDNode->get_text(&bstrID);
            spNameNode->get_text(&bstrName);

            InsertIntoDatabase(_wtoi(bstrID), bstrName);

            // Запись в текстовый файл
            std::wofstream file("data.txt", std::ios::app);
            if (file.is_open())
            {
                file << L"ID: " << (wchar_t*)bstrID << L", Name: " << (wchar_t*)bstrName << std::endl;
                file.close();
            }
        }
    }

    return S_OK;
}

HRESULT CArithmetic::InsertIntoDatabase(int id, BSTR name)
{
    CDataSource db;
    CSession session;
    CCommand<CDynamicAccessor> command;

    // Подключение к базе данных
    HRESULT hr = db.OpenFromInitializationString(L"Provider=SQLOLEDB;Data Source=YOUR_SERVER_NAME;Initial Catalog=MyDatabase;Integrated Security=SSPI;");
    if (FAILED(hr)) return hr;

    hr = session.Open(db);
    if (FAILED(hr)) return hr;

    // Подготовка SQL запроса
    CComBSTR query(L"INSERT INTO mydata (ID, Name) VALUES (");

    long longValue = 123456789;
    std::wstring longStr = std::to_wstring(longValue);

    query.Append(std::to_wstring(id).c_str());
    query.Append(L", '");
    query.AppendBSTR(name);
    query.Append(L"')");

    // Выполнение запроса
    hr = command.Open(session, query);
    if (FAILED(hr)) return hr;

    return S_OK;
}