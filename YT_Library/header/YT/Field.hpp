#ifndef FIELD_HPP
#define FIELD_HPP

#include <string>
#include <vector>
#include <functional>
#include <stdexcept>

namespace YackTerminal {

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
			 * @brief 
			 * @details
			 * @param
			 * @return
			*/
			Field(const std::string& arg_str) ;

			
			Field() = default; 

		protected: // members

			std::string m_name;

		public : //operations

			/**
			 * @brief 
			 * @details
			 * @param
			 * @return
			*/
			const std::string& operator[](size_t key) const;
			
			/**
			 * @brief 
			 * @details
			 * @param
			 * @return
			*/
			std::string name() const noexcept;
			
			/**
			 * @brief 
			 * @details
			 * @param
			 * @return
			*/
			virtual void rconstruct(const std::string& nw_arg_str);
			
			/**
			 * @brief 
			 * @details
			 * @param
			 * @return
			*/
			virtual bool inspect(const std::function<bool(const std::string&)>& predicate) const;
			
			public : // public members
			
			std::vector<std::string> m_argv;
			

	};

	
} //end of namespace 


#endif //end of file 