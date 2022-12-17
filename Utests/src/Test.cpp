#include <iostream>
#include <UnitaryTest.hpp>
#include <TestCode.hpp>
namespace yt = YackTerminal;

int main(int argc , char* argv[])
{
	//TC_FIELD();
	//UT_Other();
	//TC_FlAG();
	TC_COMMAND();
	
	std::cout<<" Exit success "<<std::endl;

	std::cin.get();
	return 0;
}