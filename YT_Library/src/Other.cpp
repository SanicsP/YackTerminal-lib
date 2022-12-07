#include <Other.hpp>

namespace YackTerminal{



std::string argv2String(int argc , char* argv[])
{
	std::string return_str;
	
	for(int i = 0 ; i < argc ; i++)
	{
		std::string c_str = argv[i];
		return_str += " " + c_str;
	}

	return return_str;
}

void say()
{
	std::cout<<"hello world"<<std::endl;
}

}