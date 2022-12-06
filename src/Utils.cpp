#include "Utils.hpp"

using namespace YackTerminal;

std::string Argv2String(int argc , char* argv[])
{
	std::string return_str;
	
	for(int i = 0 ; i < argc ; i++)
	{
		std::string c_str = argv[i];
		return_str += " " + c_str;
	}

	return return_str;
}