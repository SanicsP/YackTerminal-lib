#include <Field.hpp>

namespace YackTerminal { 


	Field::Field(size_t argc , char* argv[]) 
	{
		m_name = argv[1];
		for(int i = 2 ; i < argc ; i++)
			m_argv[i] = argv[i];
	}

	Field::Field(const std::string& arg_str) 
	{

	}

	const std::string& Field::operator[](size_t key) const
	{

	}

	std::string Field::name() const noexcept
	{

	}

	void Field::rconstruct(const std::string& nw_arg_str)
	{
		
	}

}