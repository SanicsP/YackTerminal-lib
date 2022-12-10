#include <iostream>
#include <UnitaryTest.hpp>

namespace yt = YackTerminal;

int main(int argc , char* argv[])
{
	UT_Other(argc , argv);
	
	std::cout<<"No Error"<<std::endl;
	std::cin.get();
	return 0;
}