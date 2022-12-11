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


	std::vector<std::string> stringSplit(const std::string& str , char delim)
	{
		using Cstr_it = std::string::const_iterator;
		std::vector<std::string> return_v{};

		Cstr_it mov_it{std::begin(str)};
		Cstr_it delim_it{std::begin(str)};

		auto replace = [](char delim , Cstr_it& mov_it , Cstr_it& delim_it ,
						  const std::string& str
		) -> void {

			while(true) {
			if (mov_it == std::end(str)  - 1)
			{
				
				break;
			}
			else if(*mov_it == delim && *(mov_it + 1) != delim)
			{
				delim_it = mov_it + 1;
				mov_it++;
				break;
			}
			else 
			{
				mov_it++;
			}
			}

		};

		while(mov_it != std::end(str))
		{
			if(mov_it == std::begin(str) && *mov_it == delim)
				replace(delim , mov_it , delim_it , str);
	
			
			if(*mov_it == delim )
			{
				return_v.push_back({delim_it , mov_it});
				replace(delim , mov_it , delim_it , str);
			}
			else if(mov_it == std::end(str) - 1) 
			{
				return_v.push_back({delim_it , mov_it +1 });
			}
			mov_it++;

		}
		return return_v;
		//str_____ipp 

	}
}