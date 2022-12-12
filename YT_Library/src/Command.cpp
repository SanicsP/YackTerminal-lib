#include <Command.hpp>

namespace YackTerminal {

	Command::Command(int argc , char* argv[]) 
	{

	}
	
	Command::Command(const std::string& arg_str) : Field(arg_str)
	{

	}
	void Command::rconstruct(const std::string& nw_arg_str) 
	{
		Field::rconstruct(nw_arg_str);
		size_t size = m_argv.size();
		for(int i = 0 ; i < size ; i++)
		{
			
		}

	}
	bool Command::inspect(const std::function<bool(const std::string&)>& predicate) const 
	{

	}

};
