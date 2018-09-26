
#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "DefCondition.h"

#define HRESULT



class AntivirusStatus : public DefenceStatus
{


public:
	

	virtual void defStatus() override
	{
		//get windefender status
		bool fEnable;

		HRESULT bool WDEnable( );
		
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
	{
		return defendStatus;
	};

	
};

class FirewallStatus : public DefenceStatus
{

public:
	virtual void defStatus() override
	{
		//get winfirewall status
		bool fwEnable;
		// Check to see if the firewall is on.
		if (fwEnable != VARIANT_FALSE)
		{
			defendStatus = "Firewall is on";
		}
		else
		{
			defendStatus = "Firewall is off";
		};

	}
	std::string getdefStatus()
	{
		return defendStatus;
	};
};

class AntiMalWareStatus : public DefenceStatus
{

public:
	virtual void defStatus() override
	{
	
	};

};
