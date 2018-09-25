
#include "stdafx.h"
#include <iostream>

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
		std::cout <<"Antivirus info" << AVStatus << std::endl;
		std::cout << "Firewall info" << FWStatus << std::endl;
		std::cout << "Antimalware info" << AMWStatus << std::endl;
		std::cout << "All services info" << AVStatus << FWStatus << AMWStatus << std::endl;
		std::cout << "Antivirus and Firewall info" << AVStatus << FWStatus << std::endl;
		std::cout << "Antivirus and Antimalware info" << AVStatus << AMWStatus << std::endl;
		std::cout << "Firewall and Antimalware info" << FWStatus << AMWStatus << std::endl;
		
	
	};
}