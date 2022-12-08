#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <iostream>
#include <sstream>
namespace YackTerminal {

	std::string argv2String(int argc , char* argv[]);
	char** string2Argv(const std::string& str);
	void say();
}


#endif