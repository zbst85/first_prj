// ProtectConditionWin.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "DefCondition.h"

#include <iostream>
#include <Windows.h>
#include <map>
#include <string>


#define WINDOWS_FIREWALL   L"FW"
#define WINDOWS_ANTIVIRUS  L"AV"
#define WINDOWS_DEFENDER   L"WD"



/*int main(void)
{
	
	
	
}*/


//Firewall status caller
int __cdecl wmain(int argc, wchar_t* argv[])
{

	std::wstring cmdstr(*argv);
	// cmdstr.makeuppercase

	if (cmdstr.find(WINDOWS_FIREWALL) >= 0)
	{
		FirewallStatus FWStat;
		FWStat.defStatus();

	}
	if (cmdstr.find(WINDOWS_ANTIVIRUS) >= 0)
	{
		AntivirusStatus AVstat;
		AVstat.defStatus();
	}

	return 0;
	

}
	

	





	
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
			
		}
	}

	// Retrieve the firewall profile currently in effect.
	hr = WindowsFirewallInitialize(&fwProfile);
	if (FAILED(hr))
	{
		printf("WindowsFirewallInitialize failed: 0x%08lx\n", hr);
		
	}

	// Is is turned on?
	BOOL bIsOn = false;
	hr = WindowsFirewallIsOn(fwProfile, &bIsOn);
	if (FAILED(hr))
	{
		printf("WindowsFirewallIsOn failed: 0x%08lx\n", hr);
		
	}

		
	// Uninitialize COM.
	if (SUCCEEDED(comInit))
	{
		CoUninitialize();
	}

	return 0;
}

