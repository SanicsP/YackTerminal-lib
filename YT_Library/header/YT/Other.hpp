///@file 
#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

namespace YackTerminal {
	
	/**
	* @brief 
	* @details
	* @param
	* @return
	*/
	std::string argv2String(int argc , char* argv[]);
	
	/**
	* @brief 
	* @details
	* @param
	* @return
	*/
	std::vector<std::string> stringSplit(const std::string& str , char delim);


}


#endif