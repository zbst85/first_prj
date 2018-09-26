
#include "stdafx.h"
#include "DefCondition.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <atlbase.h> // For ATL autorelease classes (CComBSTR, CComPtr)
#include <wbemidl.h> // For WMI
#include <stdio.h>
#include <netfw.h>

#define HRESULT



class AntivirusStatus : public DefenceStatus
{


public:
	

	virtual void defStatus() override
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
		
	};
	std::string getdefStatus()
	{};

	
};

class FirewallStatus : public DefenceStatus
{

public:
	virtual void defStatus() override
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
	std::string getdefStatus() {};

};

class AntiMalWareStatus : public DefenceStatus
{

public:
	virtual void defStatus() override
	{	
	};

};
