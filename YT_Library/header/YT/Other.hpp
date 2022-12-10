#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

namespace YackTerminal {
	
	std::string argv2String(int argc , char* argv[]);
	std::vector<std::string> stringSplit(const std::string& str , char delim);


}


#endif