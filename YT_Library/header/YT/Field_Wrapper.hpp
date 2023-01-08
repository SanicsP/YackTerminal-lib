#ifndef FIELD_WRAPPER_HPP
#define FIELD_WRAPPER_HPP

#include <YT/Command_Wrapper.hpp>
#include <YT/Field.hpp>

	namespace YackTerminal {

		using FieldParser = std::function<bool(const Field&)>;
		using FieldExecute = std::function<std::string(const Field&)>;

		class Field_Wrapper : public Command_Wrapper
		{
			public : //constructors 
				
				Field_Wrapper(const FieldParser& fp , const FieldExecute& fe,
							 const std::string& err_msg , const std::string& rn_msg
				);

				Field_Wrapper(const Field_Wrapper& other);

			public : //operations
				//inherited
				bool execute() const override;
			private : 
				FieldParser m_parser_func;
				FieldExecute m_execute_func;
		};

	}

#endif