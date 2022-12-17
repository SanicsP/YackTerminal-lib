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
		
		this->Field::rconstruct(nw_arg_str);
		
		if(m_argv.empty())
			throw std::invalid_argument("empty command");

		size_t size = m_argv.size();

		for(int i = 0 ; i < size ; i++)
		{
			//std::cout<<m_argv[i] << " | ";
			if(isFlag(m_argv[i] , m_delim_in , m_delim_out))
			{
				//std::cout<<"flag"<<std::endl;
				m_flagv.push_back(Flag{m_argv[i] , m_delim_in , m_delim_out , m_flag_arg_delim});
			}
			else
			{
				m_com_argv.push_back(m_argv[i]);
			}
		}
		std::cout<<"\n";

	}
	bool Command::inspect(const std::function<bool(const std::string&)>& predicate) const 
	{
		for(std::string str : m_com_argv)
		{
			if(!predicate(str))
				return false;
		}

		return true;
	}

	bool Command::hasFlag(const std::string& flag_name) const
	{
		for(Flag flg : m_flagv)
		{
			if(flg.name() == flag_name)
				return true;
		}
		return false;
	}
	
	bool Command::inspectF(const std::string& flag_name , const std::function<bool(const std::string&)>& predicate) const
	{
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
	
	std::size_t Command::argCount() const
	{
		return m_com_argv.size();
	}
	
	std::size_t Command::fArgCount(const std::string& flagName) const
	{
		for(Flag flg : m_flagv)
		{
			if(flg.name() == flagName)
			{
				return flg.m_argv.size();
			}
		}
		return 0;
	}
	
	std::size_t Command::fArgCount() const
	{
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
	
	std::size_t Command::fCount() const
	{
		if(m_flagv.empty())
			return 0;
		return m_flagv.size();
	}

	const std::string& Command::operator[](size_t key) const 
	{
		return m_com_argv[key];
	}
	

};
