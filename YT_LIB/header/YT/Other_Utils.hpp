/**
 * @file 
 * @brief fichier pour les fonctions de support de la bibliothèque
*/

#ifndef OTHER_UTILS_HPP
#define OTHER_UTILS_HPP

#include <string>
#include <algorithm>
#include <vector>

namespace YackTerminal { 
	
	/**
	 * @brief supprime dans une chaîne de caractères , entre le début/fin et un caractère non 
	 * delimitant tout les caractères de delimitation(delim) 
	 * @param string chaîne à traiter 
	 * @param delim caractère de délimitation
	 * @return retourne la chaîne netoyé de tout caractère de délimitation au début et la fin
	 * si la chaîne est vide , la fonction retournera une chaîne vide 
	 * @note cette fonction sert à la base de support pour faciliter le traitement de 
	 * raw_divide_string : la séparation de sous chaînes délimitées par un caractère de 
	 * délimitation et le stockage dans un vecteur de chaînes de caractères
	*/
	std::string clear_delim_string(const std::string& string , char delim);
	
	/**
	 * @brief à partir d'un caractère de délimitation elle divise une chaîne de caractère en 
	 * un vecteur de chaînes de caractères  
	 * @param string chaîne à traiter 
	 * @param delim caractère de délimitation
	 * @return la fonction retourne un vecteur de chaînes de caractères contenant dans chaque 
	 * case une sous-chaîne séparée par un caractère de délimitation
	*/
	std::vector<std::string> raw_divide_string(const std::string& string , char delim);
	
	/**
	* @brief affiche les valeurs d'un vecteur de chaînes de caractères dans la console 
	* @param strv le vecteur à afficher 
	*/
	void print_raw_string_vec(const std::vector<std::string>& strv);
}

#endif