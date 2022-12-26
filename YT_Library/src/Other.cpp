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
		const size_t max_argument_caracters = 255;
		std::istringstream str_stream{str};

		std::vector<std::string> split_Vector;

		char sub_stream[max_argument_caracters];

		for(int i = 0 ; str_stream.getline(sub_stream , max_argument_caracters , delim) ; )
		{
			split_Vector.push_back(sub_stream);
		}

		return split_Vector;
		//str_____ipp 

	}
}