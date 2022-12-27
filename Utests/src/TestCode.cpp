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
	std::cout<<"\n\t TC_COMMAND \n ";
	std::cout<<"--------------------------------------------------------------------\n";

	
	//UT_Command();
	std::string command;
	std::cout<<"> ";
	try {
		std::getline(std::cin , command , '\n');

		YackTerminal::Command com{command , '[' , ']' , '/'};

		bool endl_ = false;
		bool spec_ = false;
			if(com.argCount() == 0 || com.name() != "rp") {
			std::cout<<"bad syntax"<<std::endl;
			return false;
		}

		if(com.hasFlag("-el"))
		{
			std::cout<<"rawPrint with endline"<<std::endl;
			endl_ = true;
		}
		if(com.hasFlag("-sp"))
		{
			std::cout<<"rawPrint with endline"<<std::endl;
			endl_ = true;
		}
		if(com.hasFlag("-spec"))
		{
			std::cout<<"rawPrint with special char"<<std::endl;
			spec_ = true;
		}
		
		std::cout<<"Rp;";
		for(std::string str : com.m_com_argv)
		{
			std::cout<<str;
			if(endl_)
				std::cout<<'\n';
			else
				std::cout<<" ";
			if(spec_)
			{
				for(int i = 0 ; i < com["-spec"].m_argv.size(); i++)
				{
					if(!com["-spec"].inspect([](const std::string& str) -> bool {

						return std::all_of(std::begin(str) , std::end(str) , isdigit);
					}))
						std::cout<<"☻♥";
					std::cout<<com["-spec"][i];
				}
			}
		}

	}
	catch(const std::exception& ex)
	{
		std::cout<<ex.what()<<std::endl;
	}
	std::cout<<'\n';
	std::cout<<"--------------------------------------------------------------------\n";

}