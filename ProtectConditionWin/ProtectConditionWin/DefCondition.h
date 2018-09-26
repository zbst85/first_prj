#pragma once


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
	
public:
	virtual void defStatus() override;
	

};

class FirewallStatus : public DefenceStatus
{

public:
	virtual void defStatus() override;
};

class AntiMalWareStatus : public DefenceStatus
{

public:
	virtual void defStatus() override;
};


