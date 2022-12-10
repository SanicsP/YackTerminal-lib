#include <Other.hpp>

namespace YackTerminal{



	std::string argv2String(int argc , char* argv[])
	{
		std::string return_str;
		
		for(int i = 0 ; i < argc ; i++)
		{
			std::string c_str = argv[i];
			if(i != argc - 1)
				return_str += c_str + " ";
			else
				return_str += c_str;
		}

		return return_str;
	}

	char** string2Argv(const std::string& str)
	{
		char** retunr_argv = nullptr;
		std::istringstream sstr {str};
		
		
		
	}

	std::vector<std::string> stringSplit(const std::string& str , char delim)
	{
		std::vector<std::string> return_v{};

		std::string::const_iterator mov_it{std::begin(str)};
		std::string::const_iterator delim_it{std::begin(str)};

		auto replace = [](std::string::const_iterator& delim_it , 
						  std::string::const_iterator& mov_it,
		 				  char delim , const std::string& str) -> bool
		{
			auto diff = [delim](char delim2) -> bool {return delim2 == delim ; };
			
			delim_it = mov_it;
			mov_it = std::find_if_not(delim_it , std::end(str) , diff);
			
			if(mov_it == std::end(str))
				return false;
				
			mov_it--;
			delim_it = mov_it;
			mov_it++;
			return true;
		};

		while(mov_it != std::end(str))
		{
			mov_it = std::find(delim_it , std::end(str) , delim);
			return_v.push_back({delim_it , mov_it});
			replace(delim_it ,mov_it , delim ,str);

		}
		return return_v;
		//str_____ipp 

	}
}