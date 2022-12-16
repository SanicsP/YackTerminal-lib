/// @file 
 
#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <vector>
#include <functional>
#include <Field.hpp>
#include <Flag.hpp>
#include <Other.hpp>

namespace YackTerminal  
{

	/**
	 * @brief 
	 * @details
	*/
	class Command : public Field
	{

		public : // constructors
			
			/**
			 * @brief 
			 * @details
			 * @param
			 * @return
			*/
			Command(int argc , char* argv[] , char delimI , char delimO , char flag_delim);
			
			/**
			 * @brief 
			 * @details
			 * @param
			 * @return
			*/
			Command(const std::string& arg_str , char delimI , char delimO , char flag_delim);
		private :
			char m_delim_in;
			char m_delim_out;
			char m_flag_arg_delim;
		public:  // services 
			std::vector<Flag> m_flagv;

			
			/**
			 * @brief 
			 * @details
			 * @param
			 * @return
			*/
			void rconstruct(const std::string& nw_arg_str) override;
			
			/**
			 * @brief 
			 * @details
			 * @param
			 * @return
			*/
			bool inspect(const std::function<bool(const std::string&)>& predicate) const override;
			
			
	};
}

#endif