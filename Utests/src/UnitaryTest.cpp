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
	std::function<bool(const std::string&)> predicate {
		[](const std::string & str ) -> bool{
			return str.size() >= 4;
		}
	};

	yt::Flag test_flag{"test<arg1 arg2 arg3>" , '<' , '>'};
	assert(test_flag.name() == "test" &&"Assert fail in Flag class constructor");

	test_flag.rconstruct("reconstruct_test<arg1' arg2' arg3'>");
	assert(test_flag.name() == "reconstruct_test" &&"Assert fail in Flag class rconstruct function");

	bool check = test_flag.inspect(predicate);
	assert(check &&"Assert fail in Flag inspect function");

	std::cout<<std::boolalpha<<yt::isFlag("t<arg1 arg2>" , '<' , '>')<<std::endl;
	
}
