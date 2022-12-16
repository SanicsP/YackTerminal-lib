#ifndef FLAG_HPP
#define FLAG_HPP
#include "Field.hpp"

namespace YackTerminal {

	class Flag : public Field
	{
		public:

			/**
			 * @brief 
			 * @details
			 * @param
			 * @return
			*/
			Flag(const std::string& ArgStr , char deliI , char deliO , char arg_delim);
			Flag() = default;
		private:
			char m_delim_in;
			char m_delim_out;
			char m_arg_delim;
		public : 
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
		private : 
			
			/**
			 * @brief 
			 * @details
			 * @param
			 * @return
			*/
			bool isFlag(const std::string& arg) const;
	};

	bool isFlag(const std::string& arg , char delimIn , char delimOut);
}



#endif
