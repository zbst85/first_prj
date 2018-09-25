#pragma once


class CModeWindowsDefence : public CAppModeBaseT<CAppModeBase::rfNeedModeParam | CAppModeBase::rfCheckInstallFolder | CAppModeBase::rfWeakInstallFolder>
{
public:
	bool Run();
};