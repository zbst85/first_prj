#pragma once


class DefenceStatus
{
public:
	virtual void defStatus() =0 ;

	virtual ~DefenceStatus()
	{		};
};


class AntivirusStatus : public DefenceStatus
{
private:
	std::string AVStatus;

public:
	  void defStatus() override = 0
	{	};

};

class FirewallStatus : public DefenceStatus
{

private:
	std::string FWStatus;
	
public:
	virtual void defStatus() override
	{		};
};


