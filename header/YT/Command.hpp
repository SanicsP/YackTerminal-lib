#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <vector>
#include <functional>
namespace YackTerminal {

	class Command{

		public : 
			enum class ErrType;

			Command(const std::string name , int argc , char* argv[] , 
			std::function<bool(std::string)> arg_predicat);

			std::string getName();

			const std::string& operator[](size_t key);

			static ErrType Err();

		private :
			std::string m_Name;
			std::vector<std::string> m_Argv;
			bool m_Valid;
			static ErrType m_err;
		public : 

			enum class ErrType
			{
				Nocalled = 1 , 
				Invalid_Arg = 2,

			};
	};
}

#endif