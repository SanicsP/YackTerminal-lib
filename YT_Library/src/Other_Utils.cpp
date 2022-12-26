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
}