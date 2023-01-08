#ifndef COMMAND_WRAPPER_HPP
#define COMMAND_WRAPPER_HPP

#include <functional>
#include <YT/Command.hpp>
#include <string>

namespace YackTerminal
{
	
	class Command_Wrapper
	{
		protected : //fields
			std::string m_err_msg;
			std::string m_return_msg;
			bool m_stat;
		public :
			virtual bool get_stat() const;
			virtual bool execute() const = 0;

	};
} // namespace 


#endif