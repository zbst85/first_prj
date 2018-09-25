#include "StdAfx.h"
#include "ModeWindowsDefence.h"

#define WINDOWS_SECURITY_PARAM_DF_ON		L"df+"
#define WINDOWS_SECURITY_PARAM_DF_OFF		L"df-"
#define WINDOWS_SECURITY_PARAM_FW_ON		L"fw+"
#define WINDOWS_SECURITY_PARAM_FW_OFF		L"fw-"
#define WINDOWS_SECURITY_PARAM_MW_ON        L"mw+"
#define WINDOWS_SECURITY_PARAM_MW_OFF       L"mw-"

bool CModeWindowsDefence::Run()
{
	CWindowsFirewallState firewall;
	CWindowsDefenderState defender;
	if (!firewall.GetState() || !defender.GetState())
	{
		m_exitCode = 1;
		return false;
	}

	m_param.MakeLower();

	if (m_param.Find(WINDOWS_SECURITY_PARAM_FW_ON) >= 0)
	{
		cisInstallTurnWindowsFirewall(firewall);

		if (CWindowsNetworkDetectionDialog::isSupportedOnThisSystem())
			CWindowsNetworkDetectionDialog::Unsupress();
	}
	else if (m_param.Find(WINDOWS_SECURITY_PARAM_FW_OFF) >= 0)
	{
		firewall.Reset(); //all "enableXXX"=false by default
		cisInstallTurnWindowsFirewall(firewall);
		firewall.SetState();

		if (CWindowsNetworkDetectionDialog::isSupportedOnThisSystem())
			CWindowsNetworkDetectionDialog::Supress();
	}

	if (m_param.Find(WINDOWS_SECURITY_PARAM_DF_ON) >= 0)
	{
		cisInstallTurnWindowsDefender(defender);
	}
	else if (m_param.Find(WINDOWS_SECURITY_PARAM_DF_OFF) >= 0)
	{
		defender.Reset();
		cisInstallTurnWindowsDefender(defender);
		defender.SetState();
	}

	return true;
}