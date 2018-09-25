
#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "DefCondition.h"

#define HRESULT

class DefenceStatus
{
public:
	virtual void defStatus() const = 0;

	virtual ~DefenceStatus()
	{		};
	
};


class AntivirusStatus : public DefenceStatus
{
private:
	std::string AVStatus;

public:
	

	virtual  void defStatus() override
	{
		//get windefender status
		bool fEnable;

		HRESULT bool WDEnable( );
		
		fEnable = WDEnable();

		if (fEnable == true)
		
			AVStatus = "Antivirus is on";
		
		else AVStatus = "Antivirus is off";

		return AVStatus;

	}
	
};

class FirewallStatus : public DefenceStatus
{

public:
	std::string FWStatus;
	std::string defStatus()
	{
		//get winfirewall status
		bool fEnable;

		HRESULT bool WDEnable(fEnable);

		if (fEnable == true)
		{
			AVStatus = "Antivirus is on";
		}
		else AVStatus = "Antivirus is off";

		return AVStatus;

	}

	HRESULT WindowsFirewallIsOn (IN INetFwProfile* fwProfile, OUT BOOL* fwOn)
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



};
