#include <Field.hpp>

#include <Other.hpp>

namespace YackTerminal { 


	Field::Field(size_t argc , char* argv[]) 
	{
		std::string str_argv = argv2String(argc , argv);
		this->rconstruct(str_argv);
		
	}

	Field::Field(const std::string& arg_str) 
	{
		this->rconstruct(arg_str);
	}


	const std::string& Field::operator[](size_t key) const
	{
		return m_argv[key];
	}

	std::string Field::name() const noexcept
	{
		return m_name;
	}

	void Field::rconstruct(const std::string& nw_arg_str)
	{
		std::vector<std::string> arg_array = stringSplit(nw_arg_str , ' ');
		m_name = arg_array[1];
		m_argv = std::vector<std::string>{std::begin(arg_array) + 2 ,std::end(arg_array)};
	}
	
	bool Field::inspect(const std::function<bool(const std::string&)>& predicate) const 
	{
		if(m_argv.empty())
			throw std::invalid_argument("The argument's vector is empty");
		for(std::string str : m_argv)
		{
			if(!predicate(str))
				return false;
		}
		return true;
	}

}