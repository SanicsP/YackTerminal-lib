#ifndef FIELD_HPP
#define FIELD_HPP

#include <string>
#include <vector>
#include <functional>
#include <stdexcept>

namespace YackTerminal {

	/**
	 * @brief classe représentant un champ 
	 * @details un champ est un élément possédant un nom auquel lui est associé une liste de
	 * d'arguments délimités par des espaces , il représente la commande entrée par l'utilisateur lors 
	 * du lancement du programme . fourrnit des opérations de base pour faciliter le traitement de données issues 
	 * de la ligne de commande 
	*/
	class Field {
		
		public: // constructors 
			
			/**
			 * @brief Constructeur de base de la classe Field
			 * @details Construit un objet de type Field à partir d'un vecteur d'arguemnts et 
			 * de sa taille 
			 * @param argc taille du vecteur d'arguments 
			 * @param argv vecteur d'arguement , le premier élèment est le nom du programme 
			 * que l'utilisateur a inscrit en ligne de commandes
			 * @return aucune donnée en retour 
			*/
			Field(size_t argc , char* argv[]) ;
			
			/**
			 * @brief Constructeur de base de la classe field 
			 * @details Construit un objet de type Field avec une chaîne de caractères représentant 
			 * l'entrée de commande de l'utilisateur
			 * @param arg_str la chaîne de caractères sur laquelle le constructeur construit l'objet 
			 * @return aucune donnée en retour 
			*/
			Field(const std::string& arg_str) ;

			explicit Field(const Field& other);


			
			Field() = default; 

		protected: // members
			///@brief nom du champ 
			std::string m_name;

		public : //operations

			/**
			 * @brief Operateur d'accès en lecture des éléments du veteur d'argument de l'objet 
			 * de type field
			 * @param key indice d'accèss
			 * @return une référence constante vers l'élement du tableau correspondant
			 * @exception peut lancer une exception de type std::lenght_error si un accès hors du tableau 
			 * est fait 
			*/
			virtual const std::string& operator[](size_t key) const;
			
			/**
			 * @brief renvoi le nom du champ
			 * @return le nom du champ
			*/
			std::string name() const noexcept;
			
			/**
			 * @brief reconstruit un objet de type field à partir d'une chaîne de caractères 
			 * @param nw_arg_str chaîne de caractère de référence 
			 * @return aucune donnée en retour 
			 * @exception peut lancer une exception de type std::invalid argument si nw_arg_str 
			 * est une chaîne de caractères vide 
			 * @exception peut lancer une exception de type std::runtime_error si aucun nom n'est donné à la commande : 
			 * par exemple si le programme est appelé sans commande 
			 * @note à noter que le premier mot de la commande n'est pas enregistré , cela est dût au fait 
			 * que l'objet considère systématiquement le premier mot comme le nom du programme
			*/
			virtual void rconstruct(const std::string& nw_arg_str);
			
			/**
			 * @brief applique un prédicat unaire à chaque élément du vecteur d'arguments 
			 * @details le prédicat unaire doit s'agir d'une fonction avec un seul arguement de 
			 * type std::string qui retourne une valeur booléene
			 * @param predicate predicat unaire à appliquer 
			 * @return retourne vrai si tout les éléments vérifient le prédicat faux dans le cas 
			 * contraire 
			 * @exception peut lancer une exception de type std::lenght_error si un accès hors du tableau 
			 * est fait 
			*/
			virtual bool inspect(const std::function<bool(const std::string&)>& predicate) const;
			
			public : // public members
			
			/** 
			* @brief vecteur d'arguements contenant toute les chaînes de caractères constituant 
			* la commande entrée par l'utilisateur
			*/ 
			std::vector<std::string> m_argv;

			public: // operators
			void operator=(const Field& other);
			

	};

	
} //end of namespace 


#endif //end of file 