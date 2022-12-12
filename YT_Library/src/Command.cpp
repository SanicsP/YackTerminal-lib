#include <Command.hpp>

namespace YackTerminal {

	Command::Command(int argc , char* argv[] , char delimI , char delimO) : 
	m_delim_in(delimI),
	m_delim_out(delimO)
	{
		std::string arg_array = argv2String(argc , argv);
		rconstruct(arg_array);
	}
	
	Command::Command(const std::string& arg_str , char delimI , char delimO) :
	m_delim_in(delimI),
	m_delim_out(delimO)
	{
		rconstruct(arg_str);
	}

	void Command::rconstruct(const std::string& nw_arg_str) 
	{
		Field::rconstruct(nw_arg_str);
		
		size_t size = m_argv.size();

		for(int i = 0 ; i < size ; i++)
		{
			std::cout<<m_argv[i] << " | ";
			if(isFlag(m_argv[i] , m_delim_in , m_delim_out))
			{
				std::cout<<"flag"<<std::endl;
				m_flagv.push_back(Flag{m_argv[i] , m_delim_in , m_delim_out});
			}
		}
		std::cout<<"\n";

	}
	bool Command::inspect(const std::function<bool(const std::string&)>& predicate) const 
	{

	}

};
