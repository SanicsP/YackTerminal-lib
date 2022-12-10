#include <UnitaryTest.hpp>	

void UT_Field(int argc , char* argv[])
{
	YackTerminal::Field f{argc , argv};
	std::cout<<f.name()<<" "<<f[0]<<std::endl;
	bool predicate = f.inspect([](const std::string& str)-> bool {
		return str.size() > 4;
	});
	std::cout<<std::boolalpha<<predicate<<'\n';
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
