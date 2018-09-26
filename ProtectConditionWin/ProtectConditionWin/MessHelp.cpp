
#include "stdafx.h"
#include <iostream>
#include "DefCondition.h"

std::string AVStatus;
std::string FWStatus;
std::string AMWStatus;


class MessageHelper
{

public:

	static void getHelp()
	{
		std::cout << " Information about system defending status:" << std::endl <<
			"Antivirus info - input AV, Firewall info - input FW, Antimalware info - input AMV," << std::endl <<
			"All services - input ALL, Antivirus and Firewall info - input AFW, " << std::endl <<
			"Antivirus and Antimalware info - input AAM, Firewall and Antimalware info - input FAM" << std::endl <<
			"Licence information";
	};

	static void messageViewer()
	{
		getHelp();
		
		std::cout << getdefStatus() << std::endl;
		
	
	};
}