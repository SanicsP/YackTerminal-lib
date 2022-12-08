#include <Other.hpp>

namespace YackTerminal{



std::string argv2String(int argc , char* argv[])
{
	std::string return_str;
	
	for(int i = 0 ; i < argc ; i++)
	{
		std::string c_str = argv[i];
		if(i != argc - 1)
			return_str += c_str + " ";
		else
			return_str += c_str;
	}

	return return_str;
}

char** string2Argv(const std::string& str)
{
	char** retunr_argv = nullptr;
	std::istringstream sstr {str};
	
	
	
}


void say()
{
	std::cout<<"hello world"<<std::endl;
}

}