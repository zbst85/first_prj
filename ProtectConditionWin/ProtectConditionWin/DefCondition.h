#pragma once
#include "stdafx.h"

#include <windows.h>
#include <crtdbg.h>
#include <netfw.h>
#include <objbase.h>
#include <oleauto.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <atlbase.h> // For ATL autorelease classes (CComBSTR, CComPtr)
#include <wbemidl.h> // For WMI
#include <netfw.h>
#include <crtdbg.h>
#include <conio.h>

using namespace std;


#pragma comment(lib,"wbemuuid")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "oleaut32.lib")



class DefenceStatus
{
protected: 
	std::string defendStatus;

public:
	virtual void defStatus() =0 ;

	virtual std::string getdefStatus()
	{
		return defendStatus;
	};

	virtual ~DefenceStatus()
	{		};
	

};


class AntivirusStatus : public DefenceStatus
{
protected:
	bool AVCondition();
	
public:
		virtual void defStatus() override;
	

};

class FirewallStatus : public DefenceStatus
{
protected:
	HRESULT WindowsFirewallInitialize(OUT INetFwProfile** fwProfile);
	void WindowsFirewallCleanup(IN INetFwProfile* fwProfile);
	HRESULT WindowsFirewallIsOn(IN INetFwProfile * fwProfile, OUT BOOL * fwOn);
public:
	virtual void defStatus() override;
	
	
	
};

class AntiMalWareStatus : public DefenceStatus
{

public:
	virtual void defStatus() override;
};


