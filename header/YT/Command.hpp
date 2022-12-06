#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <vector>
#include <functional>


namespace YackTerminal {

	class Command{

		public : // constructors
			Command(size_t argc , char* argv[]);
			Command(const std::string& arg_str);
		private :
			
		public:  // services 
			const std::string& operator[](size_t key) const;
			std::string name() const ;
			void reconstruct(const std::string str);
			
	};
}

#endif