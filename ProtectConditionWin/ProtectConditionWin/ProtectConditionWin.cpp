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

char argc;

char getCommand()
{
	
		std::wcout << "Let us know what protect system are you interesting: av(antivirus), fw (firewall), amw (antimailware), all (all of them), a+f, a+a, f+a" << std::endl;
	    std::cin >> argc;

	// Проверяем значение на корректность 
	if (argc == 'av' || argc == 'fw' || argc == 'amw' || argc == 'all' || argc == 'a+a' || argc == 'a+f' || argc == 'f+a')
		return argc; // возвращаем в функцию main 
	else // в противном случае сообщаем пользователю, что что-то пошло не так
		std::wcout << "Oops, that input is invalid.  Please try again.\n"<<std::endl;

}


int main(void)
{

	char argc=getCommand();
		
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
	*/


	
	return 0;
}
