// ProtectConditionWin.cpp : Defines the entry point for the console application.

#include "stdafx.h"

#include <iostream>
#include <Windows.h>
#include <map>
#include <string>

/*const std::map <std::wstring, std::wstring> g_map =
{
	{ L"av", L"antivirus"},
	{ L"fw", L"firewall" },
};*/




char usask[55]; 
char antiv[] = "AV";
char firew[] = "FW";
char antimw[] = "AMW";
char Allinf[] = "ALL";
char AvFw[] = "A+F";
char AvAmw[] = "A+A";
char FwAmw[] = "F+A";
int result;
char tmp[50];


int main(void)
{
	printf("Let us know what protect system are you interesting : \n av(antivirus), fw(firewall), amw(antimailware), \n all(all of them), a + f, a + a, f + a \n");

	std::cin >> usask;
	
	result = _stricmp(usask, antiv);
	if (result == 0)
		strcpy_s(tmp, _countof(tmp), "Antivirus info");

	else if (result = _stricmp(usask, firew), result == 0)
		strcpy_s(tmp, _countof(tmp), "Firewall info");

	else if (result = _stricmp(usask, antimw), result == 0)
		strcpy_s(tmp, _countof(tmp), "AntiMailware info");

	else if (result = _stricmp(usask, Allinf), result == 0)
		strcpy_s(tmp, _countof(tmp), "All sec.system info");

	else if (result = _stricmp(usask, AvFw), result == 0)
		strcpy_s(tmp, _countof(tmp), "Antivirus & Firewall info");

	else if (result = _stricmp(usask, AvAmw), result == 0)
		strcpy_s(tmp, _countof(tmp), "Antivirus & Antimailware info");

	else if (result = _stricmp(usask, FwAmw), result == 0)
		strcpy_s(tmp, _countof(tmp), "Firewall & Antimailware info");

	else strcpy_s(tmp, _countof(tmp), "You input is wrong"); 

	printf(" %s \n ", tmp);
	
	
}
/*int main(void)
{

    


	std::wcout << argc << std::endl;

	
	/*auto args = CommandLineToArgvW(GetCommandLine(),
		&argc);
	for (int i = {}; i < argc; ++i)
	{

		if (g_map.count(args[i]))
			std::wcout << g_map.at(args[i]) << std::endl;
		else
			std::wcout << args[i] << L" invalid argument" << std::endl;

	}
		
	LocalFree(args);
	
}*/

	
