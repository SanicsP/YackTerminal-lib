#ifndef FIELD_HPP
#define FIELD_HPP

#include <string>
#include <vector>

namespace YackTerminal {

	class Field {
		
		public: // constructors 
			
			Field(size_t argc , char* argv[]) ;
			Field(const std::string& arg_str) ;

		private: // members

			std::string m_name;
			std::vector<std::string> m_argv;

		public : //operations
			
			const std::string& operator[](size_t key) const ;
			std::string name() const noexcept;
			void rconstruct(const std::string& nw_arg_str);

	};

	
} //end of namespace 


#endif //end of file 