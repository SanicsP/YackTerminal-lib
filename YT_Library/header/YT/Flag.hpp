
///@file 

#ifndef FLAG_HPP
#define FLAG_HPP
#include "Field.hpp"

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
			bool isFlag(const std::string& arg) const;
	};

	/**
	* @brief vérifie si une chaîne de carctère représente un drapeau 
	* @param arg  chaîne de carctère 
	* @return vraie si la chaîne est un drapeau , faux dans le cas contraire 
	*/
	bool isFlag(const std::string& arg , char delimIn , char delimOut);
}



#endif
