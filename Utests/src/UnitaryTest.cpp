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
	
	
	std::vector<std::string> argv2;
	argv2 = YackTerminal::stringSplit("Helloworldhahazdzdzd" , ' ');
	
	for(std::string i : argv2)
	{
		std::cout<<"["<<i<<"]\n";
	}
}
