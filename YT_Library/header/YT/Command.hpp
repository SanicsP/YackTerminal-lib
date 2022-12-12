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

	class Command : public Field
	{

		public : // constructors
			Command(int argc , char* argv[] , char delimI , char delimO , char flag_delim);
			Command(const std::string& arg_str , char delimI , char delimO , char flag_delim);
		private :
			char m_delim_in;
			char m_delim_out;
			char m_flag_arg_delim;
		public:  // services 
			std::vector<Flag> m_flagv;
	
			void rconstruct(const std::string& nw_arg_str) override;
			bool inspect(const std::function<bool(const std::string&)>& predicate) const override;
			
			
	};
}

#endif