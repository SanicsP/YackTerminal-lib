#include <YT/Other.hpp>
#include <YT/Other_Utils.hpp>

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
		std::string clear_str = clear_delim_string(str , delim);
		std::vector<std::string> split_Vector = raw_divide_string(clear_str , delim);
		return split_Vector;
		//str_____ipp 
	}
}