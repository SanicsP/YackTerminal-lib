#include <TestCode.hpp>


bool TC_FIELD()
{
	UT_Field();
	std::cout<<"\n\t TC FIELD \t\n";
	std::cout<<"--------------------------------------------------------------------\n";

	std::string com;
	YackTerminal::Field fl{"localPrinter print readme.md"};
	std::cout<<"command "<< fl.name() << " used to print "<< fl[0] <<std::endl;
	std::cout<<"enter the new command -> ";
	std::getline(std::cin , com , '\n');
	fl.rconstruct(com);
	std::cout<<" new command "<< fl.name()<<" new arg "<< fl[0] <<std::endl;
	
	std::cout<<"--------------------------------------------------------------------\n";

	
}

bool TC_FlAG()
{
	UT_Flag();
}

bool TC_COMMAND()
{
	UT_Command();
}