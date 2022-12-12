#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <vector>
#include <functional>
#include <Field.hpp>
#include <Flag.hpp>
namespace YackTerminal  
{

	class Command : public Field
	{

		public : // constructors
			Command(int argc , char* argv[]);
			Command(const std::string& arg_str);
		private :
			std::vector<Flag> m_flagv;
		public:  // services 
		
		void rconstruct(const std::string& nw_arg_str) override;
		bool inspect(const std::function<bool(const std::string&)>& predicate) const override;
			
			
	};
}

#endif