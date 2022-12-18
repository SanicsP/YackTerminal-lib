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

			//inherited override services from field class : 
			void rconstruct(const std::string& nw_arg_str) override;
			bool inspect(const std::function<bool(const std::string&)>& predicate) const noexcept override;
			const std::string& operator[](size_t key) const override;
			
			///////////
			
			
			// cheks funcs

			/**
			 * @brief vérifie si la commande contient un drapeau au nom de flag_name
			 * @param flag_name le nom du drapeau recherché 
			 * @return true si le drapeau existe , false dans le cas contraire
			*/
			bool hasFlag(const std::string& flag_name) const noexcept;

			/**
			 * @brief verifie selon un predicat tout les arguments d'un drapeau
			 * @param flag_name le nom du drapeau à vérifier 
			 * @param predicate le predicat unaire de vérification 
			 * @return vrai si tout les arguments du drapeau vérifient le prédicat , faux dans le 
			 * cas contraire 
			 * @exception peut lancer une excepetion de type std::lenght error si elle est appellé et qu'il n'existe 
			 * aucun flag dans la commande 
			*/
			bool inspectF(const std::string& flag_name , const std::function<bool(const std::string&)>& predicate) const;
			
			/**
			 * @brief verifie selon un predicat tout les arguments de tout les drapeaux
			 * @param predicate le predicat unaire de vérification 
			 * @return vrai si tout les arguments vérifient le prédicat , faux dans le 
			 * cas contraire 
			 * @exception peut lancer une excepetion de type std::lenght error si elle est appellé et qu'il n'existe 
			 * aucun flag dans la commande 
			*/
			bool inspectF(const std::function<bool(const std::string&)>& predicate) const;
			
			/**
			 * @brief verifie selon un predicat tout les arguments de tout les arguments des drapeaux 
			 * et de la commande 
			 * @param predicate le predicat unaire de vérification 
			 * @return vrai si tout les arguments vérifient le prédicat , faux dans le 
			 * cas contraire 
			 * @exception peut lancer une excepetion de type std::lenght error si elle est appellé et qu'il n'existe 
			 * aucun flag dans la commande 
			*/
			bool inspectAll(const std::function<bool(const std::string&)>& predicate)const ;

			///////////

			// info funcs 
			
			/**
			 * @brief renvoi le nombre d'arguments de la commande 
			 * @return le nombre d'argumenets de la commande  
			*/
			std::size_t argCount() const noexcept;
			
			/**
			 * @brief renvoi le nombre total d'arguments d'un drapeau de la commande 
			 * @param flagName le nom du drapeaux à analyser
			 * @return le nombre total d'arguments
			*/
			std::size_t fArgCount(const std::string& flagName) const noexcept;
			
			/**
			 * @brief renvoi le nombre total d'arguments de tout les drapeaux de la commande 
			 * @return le nombre total d'arguments
			*/
			std::size_t fArgCount() const noexcept;
			
			/**
			 * @brief renvoi le nombre total de drapeaux  
			 * @return le nombre total de drapeaux 
			*/
			std::size_t fCount() const noexcept;




			////////////

			// find funcs
			/**
			 * @brief accède à un drapeau dans le vecteur de drapeau de l'objet à partir du 
			 * nom du drapeau
			 * @param flg_name le nom du flag recherché 
			 * @return une reférence vers le drapeau ayant le nom flg_name
			 * @details si la commande contient plusieurs fois le même flag c'est la reférence du flag
			 * se trouvant le plus proche du début du tableau qui sera envoyée 
			*/
			Flag& operator[](const std::string& flg_name);
			/////////////////:
			
		public: // public members  
			///@brief vecteur d'arguments contenant tout les drapeaux de la commande
			std::vector<Flag> m_flagv;
			/// @brief vecteur d'arguments contenant tout les arguments de la commande
			std::vector<std::string> m_com_argv;
	};
}

#endif