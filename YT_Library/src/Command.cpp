#include <Command.hpp>

namespace YackTerminal {

	Command::Command(int argc , char* argv[] , char delimI , char delimO , char flag_delim) : 
	m_delim_in(delimI),
	m_delim_out(delimO),
	m_flag_arg_delim(flag_delim)
	{
		std::string arg_array = argv2String(argc , argv);
		rconstruct(arg_array);
	}
	
	Command::Command(const std::string& arg_str , char delimI , char delimO , char flag_delim) :
	m_delim_in(delimI),
	m_delim_out(delimO),
	m_flag_arg_delim(flag_delim)
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
				m_flagv.push_back(Flag{m_argv[i] , m_delim_in , m_delim_out , m_flag_arg_delim});
			}
		}
		std::cout<<"\n";

	}
	bool Command::inspect(const std::function<bool(const std::string&)>& predicate) const 
	{
		for(std::string str : m_argv)
		{
			if(!predicate(str))
				return false;
		}

		return true;
	}

	bool Command::hasFlag(const std::string& flag_name) const
	{

	}
	
	bool Command::inspectF(const std::string& flag_name , const std::function<bool(const std::string&)>& predicate) const
	{

	}
	
	bool Command::inspectF(const std::function<bool(const std::string&)>& predicate) const
	{

	}
	
	bool Command::inspectAll(const std::function<bool(const std::string&)>& predicate)const 
	{

	}
	
	std::size_t Command::aCount() const
	{

	}
	
	std::size_t Command::fArgCount(const std::string& flagName) const
	{

	}
	
	std::size_t Command::fArgCount() const
	{

	}
	
	std::size_t Command::fCount() const
	{

	}








};
