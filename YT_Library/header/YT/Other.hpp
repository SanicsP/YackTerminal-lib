///@file 
#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <sstream>

namespace YackTerminal {
	
	/**
	* @brief converti un vecteur d'arguements de type c en chaîne de caractères 
	* @param argc la taille du vecteur
	* @param argv le vecteur d'arguements 
	* @return
	*/
	std::string argv2String(int argc , char* argv[]);
	
	/**
	* @brief divise une chaîne de caractère en plusieurs sous chaînes délimités par un 
	* caractère
	* @param str chaîne à diviser 
	* @param delim le caractère délimitant les sous chaînes 
	* @return un vecteur de chaîne de caractères composé des chaînes divisés 
	* @bug lorsque la sous chaîne à la fin de la chaîne n'est composée que d'un seul caractère ,
	* elle n'est pas incorporée au vecteur de retour 
	*/
	std::vector<std::string> stringSplit(const std::string& str , char delim);


}


#endif