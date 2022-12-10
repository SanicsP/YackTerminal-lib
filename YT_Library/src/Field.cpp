#include <Field.hpp>

#include <Other.hpp>

namespace YackTerminal { 


	Field::Field(size_t argc , char* argv[]) 
	{
		std::string str_argv = argv2String(argc , argv);
		std::vector<std::string> arg_array = stringSplit(str_argv , ' ');

		m_name = arg_array[1];
		m_argv = std::vector<std::string>{std::begin(arg_array ) + 2 ,std::end(arg_array)};
		
	}

	Field::Field(const std::string& arg_str) 
	{

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
		
	}

}