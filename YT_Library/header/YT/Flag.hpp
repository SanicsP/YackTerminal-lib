#ifndef FLAG_HPP
#define FLAG_HPP
#include "Field.hpp"

namespace YackTerminal {

	class Flag : public Field
	{
		public:
			Flag(const std::string& ArgStr , char deliI , char deliO);
			Flag() = default;
		private:
			char m_delim_in;
			char m_delim_out;
		public : 
			void rconstruct(const std::string& nw_arg_str) override;
			bool inspect(const std::function<bool(const std::string&)>& predicate) const override;
		private : 
			bool isFlag(const std::string& arg) const;
	};

	bool isFlag(const std::string& arg , char delimIn , char delimOut);
}



#endif
