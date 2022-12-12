#ifndef FIELD_HPP
#define FIELD_HPP

#include <string>
#include <vector>
#include <functional>
#include <stdexcept>

namespace YackTerminal {

	class Field {
		
		public: // constructors 
			
			Field(size_t argc , char* argv[]) ;
			
			Field(const std::string& arg_str) ;

			Field() = default; 

		protected: // members

			std::string m_name;

		public : //operations

			const std::string& operator[](size_t key) const;
			std::string name() const noexcept;
			virtual void rconstruct(const std::string& nw_arg_str);
			virtual bool inspect(const std::function<bool(const std::string&)>& predicate) const;
			std::vector<std::string> m_argv;
			

	};

	
} //end of namespace 


#endif //end of file 