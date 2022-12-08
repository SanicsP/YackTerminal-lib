#include <iostream>
#include <YT/Other.hpp>
#include <YT/Field.hpp>

namespace yt = YackTerminal;

int main(int argc , char* argv[])
{
	
	
	std::cout<<"YackTerminal Test Programm ! \n";
	yt::say();
	std::cout<<argc<<"commands :"<< yt::argv2String(argc , argv) <<"\n";

	std::cin.get();
	return 0;
}