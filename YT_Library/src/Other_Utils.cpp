#include <YT/Other_Utils.hpp>
#include <iostream>

namespace YackTerminal { 
	
	std::string clear_delim_string(const std::string& string , char delim)
	{
		std::string cleared_string{string};

		std::string::const_iterator begin_it {std::cbegin(cleared_string)};
		std::string::const_iterator end_it {std::cend(cleared_string)};

		
		
		auto no_delim_predicate = [delim](char c) -> bool {
			return c != delim;
		};
		
		std::string::const_iterator not_delim_it {std::find_if(begin_it , end_it , no_delim_predicate)};


		cleared_string.erase(begin_it , not_delim_it);

		std::string::const_reverse_iterator crbegin_it {std::crbegin(cleared_string)};
		std::string::const_reverse_iterator crend_it {std::crend(cleared_string)};

		std::string::const_reverse_iterator crnot_delim_it {std::find_if(crbegin_it , crend_it , no_delim_predicate)};

		cleared_string.erase(crnot_delim_it.base() , crbegin_it.base());
		//std::cout<<*crnot_delim_it<<std::endl;
		return cleared_string;
	}

	std::vector<std::string> raw_divide_string(const std::string& string , char delim)
	{
		std::vector<std::string> string_vector;
		std::string::const_iterator head_it = std::cbegin(string);
		std::string::const_iterator leg_it = std::cbegin(string);

		auto delim_predicate = [delim](char c) -> bool {
			return c == delim;
		};

		auto replace_it = [&head_it , &leg_it](){
			leg_it++;
			head_it = leg_it;
		};

		bool last_void = false;

		while(leg_it != std::cend(string))
		{
			
			leg_it = std::find_if(head_it , std::cend(string) , delim_predicate);

			if(leg_it == std::cend(string))
			{
				string_vector.push_back({head_it , leg_it});
				break;
			}
			else if(std::string{head_it , leg_it}.empty())
			{
				replace_it();
			}
			else
			{
				string_vector.push_back({head_it , leg_it});
				replace_it();
			}
		}

		return string_vector;
	}
	void print_raw_string_vec(const std::vector<std::string>& strv)
	{
		for(auto i : strv)
		{
			std::cout<<i<<std::endl;
		}
	}
}
