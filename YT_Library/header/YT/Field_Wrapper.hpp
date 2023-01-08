#ifndef FIELD_WRAPPER_HPP
#define FIELD_WRAPPER_HPP

#include <YT/Command_Wrapper.hpp>
#include <YT/Field.hpp>

	namespace YackTerminal {

		using FieldParser = std::function<bool(const Field&)>;
		using FieldExecute = std::function<std::string(const Field&)>;

		class Field_Wrapper : public Command_Wrapper
		{
			
		};

	}

#endif