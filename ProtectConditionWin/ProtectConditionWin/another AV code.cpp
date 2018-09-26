
#include <windows.h>
#include <wbemidl.h>
#include <iostream>
#include <conio.h>
#include <atlbase.h>
#include "stdafx.h"
#include "DefCondition.h"

using namespace std;
#pragma comment(lib,"wbemuuid")

void main() {
	CoInitializeEx(0, 0);
	CoInitializeSecurity(0, -1, 0, 0, 0, 3, 0, 0, 0);
	IWbemLocator *locator = 0;
	CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (void **)&locator);
	IWbemServices * services = 0;
	wchar_t *name = L"root\\SecurityCenter2";
	if (SUCCEEDED(locator->ConnectServer(name, 0, 0, 0, 0, 0, 0, &services))) {
		printf("Connected!\n");
		//Lets get system information
		CoSetProxyBlanket(services, 10, 0, 0, 3, 3, 0, 0);
		wchar_t *query = L"Select * From AntiVirusProduct";
		IEnumWbemClassObject *e = 0;
		if (SUCCEEDED(services->ExecQuery(L"WQL", query, WBEM_FLAG_FORWARD_ONLY, 0, &e))) {
			printf("Query executed successfuly!\n");
			IWbemClassObject *object = 0;
			ULONG u = 0;
			//lets enumerate all data from this table

			std::string antiVirus;

			while (e) {
				e->Next(WBEM_INFINITE, 1, &object, &u);
				if (!u) break;//no more data,end enumeration
				CComVariant cvtVersion;
				object->Get(L"displayName", 0, &cvtVersion, 0, 0);
				wcout << cvtVersion.bstrVal << endl;
			}
		}
		else
			printf("Error executing query!\n");
	}
	else
		printf("Connection error!\n");
	//Close all used data
	services->Release();
	locator->Release();
	CoUninitialize();
	_getch();
}