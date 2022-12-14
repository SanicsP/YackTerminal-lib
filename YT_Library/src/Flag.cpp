#include <YT/Flag.hpp>
#include <YT/Other.hpp>
namespace YackTerminal {

	Flag::Flag(const std::string& ArgStr , char deliI , char deliO , char arg_delim) : 
	m_delim_in(deliI) ,
	m_delim_out(deliO),
	m_arg_delim(arg_delim)
	{
		rconstruct(ArgStr);
	}
	Flag::Flag(const Flag& other) : m_delim_in(other.m_delim_in) ,
	m_delim_out(other.m_delim_out),
	m_arg_delim(other.m_arg_delim)
	{
		m_name = other.m_name;
		m_argv = other.m_argv;
	}

	Flag::Flag(Flag&& other)
	{
		m_name = other.m_name;
		m_argv = other.m_argv;
		m_delim_in = other.m_delim_in;
		m_delim_out = other.m_delim_out;
		m_arg_delim = other.m_arg_delim;
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

	bool Flag::isFlag(const std::string& arg) const noexcept
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

	void Flag::operator=(const Flag& other)
	{
		m_name = other.m_name;
		m_argv = other.m_argv;
		m_delim_in = other.m_delim_in;
		m_delim_out = other.m_delim_out;
		m_arg_delim = other.m_arg_delim;
	}
	//===========================================================================================







	
	///Free func ==============================================================================

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

	bool isPart_Of_Flag(const std::string& str , char delimIn , char delimOut)
	{
		if(std::count(std::begin(str) , std::end(str) , delimIn) != 1)
				return false;
			else if(str.front() == delimIn)
				return false;
			else if (std::count(std::begin(str) , std::end(str) , delimOut) > 0)
				return false;

			return true;
	}

	bool isEnd_Of_Flag(const std::string& str , char delimIn , char delimOut)
	{
		if(std::count(std::begin(str) , std::end(str) , delimOut) != 1)
			return false;
		else if(str.back() != delimOut)
			return false;
		else if (std::count(std::begin(str) , std::end(str) , delimIn) > 0)
			return false;
		
		return true;
	}

	std::pair<std::string , std::vector<std::string>::const_iterator> repastFlag(const std::vector<std::string>& argv , 
	const std::vector<std::string>::const_iterator& initFlagPos , 
							char delimIn , char delimOut , char arg_delim)
	{
		
		std::string flag_first_part = *initFlagPos;
		std::vector<std::string>::const_iterator secondFlagPos;

		//std::cout<<"1"<<std::endl;
		//std::cout<<flag_first_part<<" is a part of flag "<<std::endl;

		///////////////////first part check /////////////////////////////////////////////
		if(!isPart_Of_Flag(flag_first_part , delimIn , delimOut))
			return {"" , std::cend(argv)};;
		
		///////////////////second part check /////////////////////////////////////////////
				
		// predicat that chek if in str vector there are close character of flag
		auto second_part_flag_predicate = [delimOut , delimIn](const std::string& str) -> bool {

			if(std::count(std::begin(str) , std::end(str) , delimOut) != 1)
				return false;
			else if(str.back() != delimOut)
				return false;
			else if (std::count(std::begin(str) , std::end(str) , delimIn) > 0)
				return false;
			return true;
		};

		
		secondFlagPos = std::find_if(initFlagPos , std::cend(argv) , second_part_flag_predicate);
		// std::cout<<"2"<<std::endl;
		if(secondFlagPos == std::cend(argv))
			return {"" , std::cend(argv)};
		
		//////////////////////repast the flag/////////////////////////////////////////////
		// predicat that chek if between open and close character there another flag
		auto flag_predicate = [delimOut , delimIn](const std::string& str) -> bool {

			if(isPart_Of_Flag(str , delimIn , delimOut) == true) 
				return true;
			else if(std::count(std::begin(str) , std::end(str) , delimIn) > 0 || 
					std::count(std::begin(str) , std::end(str) , delimOut) > 0 
			)
				return true;
			return false;
		};
		
		std::string flag_str;
		std::vector<std::string>::const_iterator return_it = initFlagPos;

		// std::cout<<"3"<<std::endl;


		if(std::count_if(initFlagPos + 1 , secondFlagPos , flag_predicate) > 0)
			return {"" , std::cend(argv)};
		else {
			while(return_it != secondFlagPos + 1)
			{
				flag_str+= *return_it;
				if(return_it != secondFlagPos)
					flag_str+= arg_delim;
				return_it++;
			}
		}

		// std::cout<<"4"<<std::endl;
		return {flag_str , return_it};

	}


};

