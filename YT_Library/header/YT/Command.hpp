/// @file 
 
#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <vector>
#include <functional>
#include <Field.hpp>
#include <Flag.hpp>
#include <Other.hpp>

namespace YackTerminal  
{

	/**
	 * @brief Classe représentant l'entrée d'une commande de l'utilisateur lors de l'appel 
	 * d'un programme 
	 * @details Tout ce que l'entrée de commande peut contenir : le nom de la commande , les arguments 
	 * de la commande , les spécifications suplémentaires avec leurs arguments 
	*/
	class Command : public Field
	{

		public : // constructors
			
			/**
			 * @brief Constructeur de base de la classe command
			 * @details Construit un objet de type commande à l'aide d'un vecteur d'arguments 
			 * et de sa taille 
			 * @param argc la taille du vecteur d'arguements 
			 * @param argv vecteur d'argument
			 * @param delimI caractère de délimitation ouvrant pour les drapeaux ex : [ , < 
			 * @param delimO caractère de délimitation fermant pour les drapeaux ex : ] , >
			 * @param delimO caractère de délimitation pour les arguments des flags : " " , "," , "|"
			 * "/" 
			 * @return aucune donnée en retour 
			*/
			Command(int argc , char* argv[] , char delimI , char delimO , char flag_delim);
			

			/**
			 * @brief Constructeur de base de la classe command
			 * @details Construit un objet de type commande à partir d'une chaîne de caractères 
			 * @param argc la taille du vecteur d'arguements 
			 * @param argv vecteur d'argument
			 * @param delimI caractère de délimitation ouvrant pour les drapeaux ex : [ , < 
			 * @param delimO caractère de délimitation fermant pour les drapeaux ex : ] , >
			 * @param delimO caractère de délimitation pour les arguments des flags : " " , "," , "|"
			 * "/" 
			 * @return aucune donnée en retour 
			*/
			Command(const std::string& arg_str , char delimI , char delimO , char flag_delim);
		private :
			char m_delim_in;
			char m_delim_out;
			char m_flag_arg_delim;
		public:  // services 
			///@brief vecteur d'arguments du drapeau
			std::vector<Flag> m_flagv;

			//inherited override services from field class : 
			void rconstruct(const std::string& nw_arg_str) override;
			bool inspect(const std::function<bool(const std::string&)>& predicate) const override;
			
			
	};
}

#endif