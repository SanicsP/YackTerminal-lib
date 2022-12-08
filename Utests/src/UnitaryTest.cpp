#include <UnitaryTest.hpp>


void UT_Field()
{

}

void UT_Command()
{

}

void UT_Other()
{
	std::string msg {"assertion fail ! in func : "};
	std::string compare{"Utest test"};
	char* argv1[] = {"Utes" , "test"};
	int argc1 = 2;
	assert((YackTerminal::argv2String(argc1 , argv1) == compare ) && "argv2string Err");
	

}
