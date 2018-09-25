
#include "stdafx.h"
#include <iostream>
#include <string>

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

public:
	std::string AVStatus;
	std::string defStatus()
	{
		//get windefender status
		bool fEnable;

		HRESULT bool WDEnable (fEnable);
		
		if (fEnable = true)
		{
			AVStatus = "Antivirus is on";
		}
		else AVStatus = "Antivirus is off";

		return AVStatus;

	}
	
};
