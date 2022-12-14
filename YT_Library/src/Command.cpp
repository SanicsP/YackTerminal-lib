#include <YT/Command.hpp>

namespace YackTerminal {

	Command::Command(int argc , char* argv[] , char delimI , char delimO , char flag_delim) : 
	m_delim_in(delimI),
	m_delim_out(delimO),
	m_flag_arg_delim(flag_delim),
	m_error_stat(Command_Error::good)
	{
		std::string arg_array = argv2String(argc , argv);
		rconstruct(arg_array);
	}
	
	Command::Command(const std::string& arg_str , char delimI , char delimO , char flag_delim) :
	m_delim_in(delimI),
	m_delim_out(delimO),
	m_flag_arg_delim(flag_delim),
	m_error_stat(Command_Error::good)
	{
		rconstruct(arg_str);
	}

	Command::Command(const Command& other) : 
		m_delim_in (other.m_delim_in),
		m_delim_out (other.m_delim_out),
		m_flag_arg_delim(other.m_flag_arg_delim),
		m_error_stat(other.m_error_stat)
	{
		m_com_argv = other.m_com_argv;
		m_argv = other.m_argv;
		m_flagv = other.m_flagv;
		m_name = other.m_name;
	}

	void Command::operator=(const Command& other)
	{
		m_name = other.m_name;
		m_delim_in =other.m_delim_in;
		m_delim_out = other.m_delim_out;
		m_flag_arg_delim = other.m_flag_arg_delim;
		m_error_stat = other.m_error_stat;

		m_com_argv = other.m_com_argv;
		m_argv = other.m_argv;
		m_flagv = other.m_flagv;
	}

	void Command::rconstruct(const std::string& nw_arg_str) 
	{
		
		this->Field::rconstruct(nw_arg_str);
		
		//if(m_argv.empty())
		//	throw std::invalid_argument("Empty command");

		size_t size = m_argv.size();

		std::vector<std::string>::const_iterator argv_it = std::cbegin(m_argv);

		while(argv_it != std::cend(m_argv))
		{
			//std::cout<<"analysing : "<<*argv_it<< "\n";
			
			if(isFlag(*argv_it , m_delim_in , m_delim_out))
			{
				m_flagv.push_back(Flag{*argv_it , m_delim_in , 
					m_delim_out , m_flag_arg_delim});
			}
			else if(isPart_Of_Flag(*argv_it , m_delim_in , m_delim_out))
			{
				std::pair<std::string , std::vector<std::string>::const_iterator> flag_str = 
				repastFlag(m_argv , argv_it , m_delim_in , m_delim_out , m_flag_arg_delim);
				
				//std::cout<<"repast flag : "<<flag_str.first<<"\n";
				
				if(flag_str.first != ""){
					
					//std::cout<<"no flag"<<std::endl;
					
					m_flagv.push_back(Flag{flag_str.first , m_delim_in , 
					m_delim_out , m_flag_arg_delim});
					argv_it = flag_str.second;
					continue;
				}
				else // if only the in delimiter is entred
				{
					m_com_argv.push_back(*argv_it);
					m_error_stat = Command_Error::bad_flag;
				}
			}
			/*else if(isEnd_Of_Flag(*argv_it , m_delim_in , m_delim_out))
			{
				argv_it++;
				continue;
			}*/
			else
			{
				m_com_argv.push_back(*argv_it);
			}

			argv_it++;
		}
		std::cout<<"\n";

	}
	bool Command::inspect(const std::function<bool(const std::string&)>& predicate) const noexcept
	{
		if(m_com_argv.empty())
			throw std::length_error("std::lenght_error : Out of bound access , empty vector");

		for(std::string str : m_com_argv)
		{
			if(!predicate(str))
				return false;
		}

		return true;
	}

	bool Command::hasFlag(const std::string& flag_name) const noexcept
	{
		if(m_flagv.empty())
			return false;

		for(Flag flg : m_flagv)
		{
			if(flg.name() == flag_name)
				return true;
		}
		return false;
	}
	
	bool Command::inspectF(const std::string& flag_name , const std::function<bool(const std::string&)>& predicate) const
	{
		if(m_flagv.empty())
			throw std::length_error("std::lenght_error : Out of bound access , empty vector");

		for(Flag flg : m_flagv)
		{
			if(flg.name() == flag_name)
			{
				if(!flg.inspect(predicate))
					return false;
				return true;
			}
		}
	}
	
	bool Command::inspectF(const std::function<bool(const std::string&)>& predicate) const
	{
		if(m_flagv.empty())
			throw std::length_error("std::lenght_error : Out of bound access , empty vector");

		for(Flag flg : m_flagv)
		{
			if(!flg.inspect(predicate))
				return false;
		}
		return true;
	}
	
	bool Command::inspectAll(const std::function<bool(const std::string&)>& predicate)const 
	{

		return inspectF(predicate) && inspect(predicate);

	}
	
	std::size_t Command::argCount() const noexcept
	{
		return m_com_argv.size();
	}
	
	std::size_t Command::fArgCount(const std::string& flagName) const noexcept
	{
		if(m_flagv.empty())
			return 0;

		for(Flag flg : m_flagv)
		{
			if(flg.name() == flagName)
			{
				return flg.m_argv.size();
			}
		}
		return 0;
	}
	
	std::size_t Command::fArgCount() const noexcept
	{
		if(m_flagv.empty())
			return 0;
			
		std::size_t count = 0;
		for(Flag flg : m_flagv)
		{
			if(!flg.m_argv.empty())
			{
				count += flg.m_argv.size();
			}
		}

		return count;
	}
	
	std::size_t Command::fCount() const noexcept
	{
		return m_flagv.size();
	}

	const std::string& Command::operator[](size_t key) const 
	{
		if(key > m_com_argv.size() - 1)
			throw std::length_error("std::lenght_error : Out of bound access , empty vector");
		return m_com_argv[key];
	}
	Flag& Command::operator[](const std::string& flg_name)
	{
		if(m_flagv.empty())
			throw std::length_error("std::lenght_error : Out of bound access , empty vector");
		
		for(int i = 0 ; i < m_flagv.size() ; i++)
		{
			if(m_flagv[i].name() == flg_name)
				return m_flagv[i];
		}
		
	}

	Command_Error Command::stat() const
	{
		return m_error_stat;
	}


};
