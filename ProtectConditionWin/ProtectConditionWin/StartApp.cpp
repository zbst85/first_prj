// ProtectConditionWin.cpp : Defines the entry point for the console application.

#include "stdafx.h"

#include <iostream>
#include <Windows.h>
#include <map>
#include <string>
#include "DefCondition.h"




/*int main(void)
{
	
	
	
}*/


//Firewall status caller
int __cdecl wmain(int argc, wchar_t* argv[])
{
	HRESULT hr = S_OK;
	HRESULT comInit = E_FAIL;
	INetFwProfile* fwProfile = NULL;

	// Initialize COM.
	comInit = CoInitializeEx(
		0,
		COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE
	);


	if (comInit != RPC_E_CHANGED_MODE)
	{
		hr = comInit;
		if (FAILED(hr))
		{
			printf("CoInitializeEx failed: 0x%08lx\n", hr);
			goto error;
		}
	}

	// Retrieve the firewall profile currently in effect.
	hr = FirewallStatus::WindowsFirewallInitialize(&fwProfile);
	if (FAILED(hr))
	{
		printf("WindowsFirewallInitialize failed: 0x%08lx\n", hr);
		goto error;
	}

	// Is is turned on?
	BOOL bIsOn = false;
	hr = FirewallStatus::WindowsFirewallIsOn(fwProfile, &bIsOn);
	if (FAILED(hr))
	{
		printf("WindowsFirewallIsOn failed: 0x%08lx\n", hr);
		goto error;
	}

error:

	// Release the firewall profile.
	FirewallStatus::WindowsFirewallCleanup(fwProfile);

	// Uninitialize COM.
	if (SUCCEEDED(comInit))
	{
		CoUninitialize();
	}

	return 0;
}
