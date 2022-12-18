#include <Flag.hpp>
#include <Other.hpp>
namespace YackTerminal {

	Flag::Flag(const std::string& ArgStr , char deliI , char deliO , char arg_delim) : 
	m_delim_in(deliI) ,
	m_delim_out(deliO),
	m_arg_delim(arg_delim)
	{
		rconstruct(ArgStr);
	}
	void Flag::rconstruct(const std::string& nw_arg_str ) 
	{
		using StrIt = std::string::const_iterator;
		if(!isFlag(nw_arg_str))
			throw std::invalid_argument("Invalid flag");
		
		StrIt delimI_it = std::find(std::begin(nw_arg_str) , std::end(nw_arg_str) , m_delim_in);
		
		StrIt delimO_it = std::find(std::begin(nw_arg_str) , std::end(nw_arg_str) , m_delim_out);

		m_name = {std::begin(nw_arg_str) , delimI_it};

		std::string sub_str = {delimI_it + 1 , delimO_it};

		m_argv = stringSplit(sub_str , m_arg_delim);
	}

	bool Flag::inspect(const std::function<bool(const std::string&)>& predicate) const 
	{
		if(m_argv.empty())
			throw std::length_error("std::lenght_error : Out of bound access , empty vector");
			
		for(std::string str : m_argv)
		{
			if(!predicate(str))
				return false;
		}
		return true;
	}

	bool Flag::isFlag(const std::string& arg) const 
	{
		if(
			std::count(std::begin(arg) , std::end(arg) , m_delim_in) != 1 ||
			std::count(std::begin(arg) , std::end(arg) , m_delim_out) != 1 
		)
			return false;
		if(
			arg.back() != m_delim_out || arg.front() == m_delim_in
		)
			return false;
		return true;
	}
	
	///Free func 

	bool isFlag(const std::string& arg , char delimIn , char delimOut)
	{
		if(
			std::count(std::begin(arg) , std::end(arg) , delimIn) != 1 ||
			std::count(std::begin(arg) , std::end(arg) , delimOut) != 1 
		)
			return false;
		if(
			arg.back() != delimOut || arg.front() == delimIn
		)
			return false;
		return true;
	}


};

