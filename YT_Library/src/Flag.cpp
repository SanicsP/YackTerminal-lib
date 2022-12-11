#include <Flag.hpp>
#include <Other.hpp>
namespace YackTerminal {

	Flag::Flag(const std::string& ArgStr , char deliI , char deliO) : 
	m_delim_in(deliI) ,
	m_delim_out(deliO)
	{
		rconstruct(ArgStr);
	}
	void Flag::rconstruct(const std::string& nw_arg_str ) 
	{
		using StrIt = std::string::const_iterator;
		if(!isFalg(nw_arg_str))
			throw std::invalid_argument("Invalid flag");
		
		StrIt delimI_it = std::find(std::begin(nw_arg_str) , std::end(nw_arg_str) , m_delim_in);
		
		StrIt delimO_it = std::find(std::begin(nw_arg_str) , std::end(nw_arg_str) , m_delim_out);

		m_name = {std::begin(nw_arg_str) , delimI_it};

		std::string sub_str = {delimI_it + 1 , delimO_it};

		m_argv = stringSplit(sub_str , ' ');
	}

	bool Flag::inspect(const std::function<bool(const std::string&)>& predicate) const 
	{
		for(std::string str : m_argv)
		{
			if(!predicate(str))
				return false;
		}
		return true;
	}

	bool Flag::isFalg(const std::string& arg) const 
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
	

};