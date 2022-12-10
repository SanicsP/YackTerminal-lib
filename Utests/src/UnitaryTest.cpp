#include <UnitaryTest.hpp>	

void UT_Field()
{
	// YackTerminal::Field TestField{}; // Constructor test
}

void UT_Command()
{

}

void UT_Other(int argc , char* argv[])
{

	std::string compare{"Utest test"};
	char* argv1[] = {"Utest" , "test"};
	int argc1 = 2;
	assert((YackTerminal::argv2String(argc1 , argv1) == compare ) && "argv2string Err");
	
	std::string argvStr = YackTerminal::argv2String(argc , argv);
	std::vector<std::string> argv2;
	argv2 = YackTerminal::stringSplit(argvStr , ' ');
	
	for(std::string i : argv2)
	{
		std::cout<<"["<<i<<"]\n";
	}
}
