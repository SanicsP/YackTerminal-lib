#include <UnitaryTest.hpp>	

namespace yt = YackTerminal;

void UT_Field()
{
	std::string assert_msg{"assertion fail : "};
	//Test of constructors
	{
		//ield(size_t argc , char* argv[])
		int argc = 4;
		char* argv[] {
			"prog" , "command" , "arg1" , "arg2"
		};

		auto predicate = [](const std::string& str) -> bool {return str.size() >= 4;};
		yt::Field field{argc , argv};
	
		assert(field.name() == "command" && "assert fail : constructor(int argc , char* argv[])");
		
		assert(field[0] == "arg1" && field[1] == "arg2" &&  "assert fail : constructor");
		
		assert(field.inspect(predicate) == true && "asset fail in func inspect()");
		
		/////////////////////////////////////////////////////

		yt::Field field2{"prog command arg1 arg2"};

		assert(field2.name() == "command" && "assert fail : constructor(std::string)");
		
		assert(field2[0] == "arg1" && field2[1] == "arg2" &&  "assert fail : constructor");
		
		assert(field2.inspect(predicate) == true && "function inspect(predicat)");

		field.rconstruct(" Program  command' arg1' arg2' arg3' ");
		assert(field.name() == "command'"&& "func reconstruct");
		assert(field[0] == "arg1'" && "func reconstruct");

	}
	//End 
}

void UT_Command()
{

}

void UT_Other()
{

}

void UT_Flag()
{
	auto predicate = [](const std::string& str) -> bool {
		return str.size() >= 4;
	};

	yt::Flag f{"-flag[arg1 arg2]" , '[' , ']'};
	std::cout<<f.name()<<" -> "<<f[0]<<" , "<<f[1]<<std::endl;
	std::cout<<std::boolalpha<<f.inspect(predicate)<<std::endl;
}
