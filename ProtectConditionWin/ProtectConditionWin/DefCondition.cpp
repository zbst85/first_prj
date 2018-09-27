
#include "stdafx.h"

#include "DefCondition.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <atlbase.h> // For ATL autorelease classes (CComBSTR, CComPtr)
#include <wbemidl.h> // For WMI
#include <stdio.h>
#include <netfw.h>
#include <crtdbg.h>
#include <netfw.h>
#include <objbase.h>
#include <oleauto.h>
#include <conio.h>

using namespace std;


#pragma comment(lib,"wbemuuid")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "oleaut32.lib")



void AntivirusStatus::defStatus()
{
	//get windefender status
	bool fEnable;

	fEnable = WDEnable();

	if (fEnable == true)
	{
		defendStatus = "Antivirus is on";
	}
	else
	{
		defendStatus = "Antivirus is off";
	};

}

void AntivirusStatus::AVCondition()
{
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

void FirewallStatus ::defStatus() 
	{
	
		bool fwEnable;
	
		if (fwEnable != VARIANT_FALSE)
		{
			defendStatus = "Firewall is on";
		}
		else
		{
			defendStatus = "Firewall is off";
		};

	}
	
HRESULT FirewallStatus::WindowsFirewallInitialize(OUT INetFwProfile** fwProfile)
{
	HRESULT hr = S_OK;
	INetFwMgr* fwMgr = NULL;
	INetFwPolicy* fwPolicy = NULL;

	_ASSERT(fwProfile != NULL);

	*fwProfile = NULL;

	// Create an instance of the firewall settings manager.
	hr = CoCreateInstance(
		__uuidof(NetFwMgr),
		NULL,
		CLSCTX_INPROC_SERVER,
		__uuidof(INetFwMgr),
		(void**)&fwMgr
	);
	if (FAILED(hr))
	{
		printf("CoCreateInstance failed: 0x%08lx\n", hr);
		goto error;
	}

	// Retrieve the local firewall policy.
	hr = fwMgr->get_LocalPolicy(&fwPolicy);
	if (FAILED(hr))
	{
		printf("get_LocalPolicy failed: 0x%08lx\n", hr);
		goto error;
	}

	// Retrieve the firewall profile currently in effect.
	hr = fwPolicy->get_CurrentProfile(fwProfile);
	if (FAILED(hr))
	{
		printf("get_CurrentProfile failed: 0x%08lx\n", hr);
		goto error;
	}

error:

	// Release the local firewall policy.
	if (fwPolicy != NULL)
	{
		fwPolicy->Release();
	}

	// Release the firewall settings manager.
	if (fwMgr != NULL)
	{
		fwMgr->Release();
	}

	return hr;
}

void FirewallStatus::WindowsFirewallCleanup(IN INetFwProfile* fwProfile)
{
	// Release the firewall profile.
	if (fwProfile != NULL)
	{
		fwProfile->Release();
	}
}

HRESULT FirewallStatus::WindowsFirewallIsOn(IN INetFwProfile* fwProfile, OUT BOOL* fwOn)
{
	HRESULT hr = S_OK;
	VARIANT_BOOL fwEnabled;

	_ASSERT(fwProfile != NULL);
	_ASSERT(fwOn != NULL);

	*fwOn = FALSE;

	// Get the current state of the firewall.
	hr = fwProfile->get_FirewallEnabled(&fwEnabled);
	if (FAILED(hr))
	{
		printf("get_FirewallEnabled failed: 0x%08lx\n", hr);
		goto error;
	}

	// Check to see if the firewall is on.
	if (fwEnabled != VARIANT_FALSE)
	{
		*fwOn = TRUE;
		printf("The firewall is on.\n");
	}
	else
	{
		printf("The firewall is off.\n");
	}

error:

	return hr;
}



class AntiMalWareStatus : public DefenceStatus
{

public:
	virtual void defStatus() override
	{	
	};

};
