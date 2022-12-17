#include <TestCode.hpp>


bool TC_FIELD()
{
	UT_Field();
	std::cout<<"\n\t TC FIELD \t\n";
	std::cout<<"--------------------------------------------------------------------\n";

	std::string com;
	YackTerminal::Field fl{"localPrinter print readme.md"};
	std::cout<<"command "<< fl.name() << " used to print "<< fl[0] <<std::endl;
	
	

	/// test 
		
		std::cout<<"RawPrint command test : ";
		
		bool good = false;
		
		while(!good) {
			try {
				std::cout<<"> ";
				std::getline(std::cin , com , '\n');
				fl.rconstruct(com);

				if(fl.name() != "rp"){
					std::cout<<"bad command\n";
					continue;
				}
				if(fl.m_argv.empty()){
					std::cout<<"noting arg\n";
					continue;
				}
			}
			catch(const std::exception& ex){
				std::cout<<ex.what()<<std::endl;
				continue;
			}

			good = true;
		}

		for(std::string str : fl.m_argv)
		{
			std::cout<<"RAW_PRINT ->\t"<<str<<'\n';
		}
	/// end test 

	

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