
///@file 

#ifndef FLAG_HPP
#define FLAG_HPP
#include <YT/Field.hpp>

namespace YackTerminal {

	/**
	 * @brief classe representant le drapeau d'une commande , une spécification suplémentaire 
	 * modifiant le comportement d'une commande 
	*/
	class Flag : public Field
	{
		public:

			/**
			 * @brief Constrcuteur de la classe  Flag 
			 * @details Construit un objet de type flag à partir d'une chaîne de caractères  
			 * @param ArgStr chaîne de carctères sur laquelle se fera la construction
			 * @param deliI caractère de délimitaion ouvrant ex : [ ou  < 
			 * @param deliO caractère de délimitaion fermant ex : ] ou  >
			 * @param deliO caractère de délimitaion des arguments : , ou |    
			 * @return 
			*/
			Flag(const std::string& ArgStr , char deliI , char deliO , char arg_delim);

			Flag(const Flag& other);
			explicit Flag(Flag&& other);
			Flag() = default;
		private:
			char m_delim_in;
			char m_delim_out;
			char m_arg_delim;
		public : 
			void rconstruct(const std::string& nw_arg_str) override;
			bool inspect(const std::function<bool(const std::string&)>& predicate) const override;
		private : 
			
			/**
			 * @brief vérifie si une chaîne de carctère représente un drapeau 
			 * @param arg  chaîne de carctère 
			 * @return vraie si la chaîne est un drapeau , faux dans le cas contraire 
			*/
			bool isFlag(const std::string& arg) const noexcept;
		public : //operators 
			void operator=(const Flag& other);
	};

	/**
	* @brief vérifie si une chaîne de carctère représente un drapeau 
	* @param arg  chaîne de carctère 
	* @return vraie si la chaîne est un drapeau , faux dans le cas contraire 
	*/
	bool isFlag(const std::string& arg , char delimIn , char delimOut);
	
	/**
	 * @brief verifie si une chaîne de caractères d'un vecteur est la première partie 
	 * d'un drapeau
	 * @param str la chaîne à traiter 
	 * @param celimIn le caractère ouvrant 
	 * @param delimOut le caractère fermant
	 * @return vrai si la chaîne est une partie d'un drapeau , faux dans le cas contraire
	*/
	bool isPart_Of_Flag(const std::string& str , char delimIn , char delimOut);

	bool isEnd_Of_Flag(const std::string& str , char delimIn , char delimOut);

	/**
	 * @brief dans un vecteur de chaîne de caractère , rassemble dans une même chaîne de 
	 * caractères des parties de drapeaux séparés par StringSplit
	 * @details cette fonction résout le problème de séparation d'un drapeau. L'orsque celui-ci 
	 * delimite ses arguments par des caractères d'espacement Field::reconstruct n'identifie pas le 
	 * drapeau et le voit comme plusieurs arguments séparés par des espaces , cela a pour conséquance 
	 * de rendre la délimitation des arguments par un espace impossible
	 * à noter qu'un drapeau commence par son nom suivi du délimiteur ouvrant et se termine par le 
	 * délimiteur fermant , entre les deux il y a les arguments du drapeau 
	 * @param argv le vecteur de chaîne de caractères à traiter 
	 * @param initFlagpos la position du début du drapeau dans le tableau 
	 * @param delimIn caractère ouvrant du drapeau 
	 * @param delimOut caractère fermant du drapeau
	 * @param arg_delim caractère de délimitation des arguments du drapeau
	 * @return un doublet std::pair<std::string , std::vector<std::string>::const_iterator> 
	 * le first est las chaîne de cararctère du drapeau rassemblé et le second
	 * est un itérateur pointant sur la chaîne de caractère contenant le caractère fermant
	 * si une erreur est rencontrée la fonction renverra un doublet avec une chaîne vide et un 
	 * itérateur pointant à la fin de argv 
	*/
	std::pair<std::string , std::vector<std::string>::const_iterator> repastFlag(const std::vector<std::string>& argv , 
	const std::vector<std::string>::const_iterator& initFlagPos, 
							char delimIn , char delimOut , char arg_delim);

}



#endif
