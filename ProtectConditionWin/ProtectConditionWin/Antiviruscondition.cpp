
#include "stdafx.h"
#include <string>
#include <atlbase.h> // For ATL autorelease classes (CComBSTR, CComPtr)
#include <wbemidl.h> // For WMI
#pragma comment(lib, "wbemuuid.lib")// Link to WMI library. (Can do in library includes instead)
#include<iostream>
using namespace std;


std::string GetAntivirusName()
{
	HRESULT hr = ::CoInitializeSecurity(NULL, -1, NULL, NULL,
		RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE,
		NULL, EOAC_NONE, NULL);

	CComPtr<IWbemLocator> pWbemLocator;
	hr = pWbemLocator.CoCreateInstance(CLSID_WbemLocator);

	CComPtr<IWbemServices> pWbemServices;
	//'Security Center' for WMI prior to Windows Vista is: '\root\SecurityCenter'
	//'Security Center' for WMI for Windows Vista and above is: '\root\SecurityCenter2'

	hr = pWbemLocator->ConnectServer(CComBSTR(L"root\\SecurityCenter2"), NULL, NULL, 0, NULL, 0, NULL, &pWbemServices);

	CComPtr<IEnumWbemClassObject> pEnum;
	CComBSTR cbsQuery = L"Select * From AntivirusProduct";
	hr = pWbemServices->ExecQuery(CComBSTR("WQL"), cbsQuery, WBEM_FLAG_FORWARD_ONLY, NULL, &pEnum);

	ULONG uObjectCount = 0;
	CComPtr<IWbemClassObject> pWmiObject;
	hr = pEnum->Next(WBEM_INFINITE, 1, &pWmiObject, &uObjectCount);

	CComVariant cvtVersion;
	hr = pWmiObject->Get(L"displayName", 0, &cvtVersion, 0, 0);

	std::string antivirus_name = CW2A(cvtVersion.bstrVal);
	return antivirus_name;
}

int _tmain(int argc, _TCHAR* argv[])
{
	HRESULT hr = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
	std::string antivirus_name = GetAntivirusName();
	::CoUninitialize();
	cout << antivirus_name << endl;

	return 0;
}
