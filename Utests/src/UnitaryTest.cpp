#include <UnitaryTest.hpp>	

namespace yt = YackTerminal;

void UT_Other()
{
	 
	std::vector<std::string> test{yt::stringSplit(" f  1 3  " , ' ')};
	assert(test[0] == "f" && "assert fail in stringSplit");
	assert(test[1] == "1" && "assert fail in stringSplit");
	assert(test[2] == "3" && "assert fail in stringSplit");
	

	std::string cleared = yt::clear_delim_string("--hello--world--" , '-');
	std::cout<<cleared<<std::endl;
	assert(cleared == "hello--world" && "assert error");

	std::vector<std::string> argv = yt::raw_divide_string("  hello  this  is a   1" , ' ');
	std::cout<<"pass : "<<std::endl;
	yt::print_raw_string_vec(argv);

}

void UT_Field()
{
	std::string assert_msg{"assertion fail : "};
	//Test of constructors
	{
		//field(size_t argc , char* argv[])
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

void UT_Flag()
{
	std::function<bool(const std::string&)> predicate {
		[](const std::string & str ) -> bool{
			return str.size() >= 4;
		}
	};

	yt::Flag test_flag{"test<arg1/arg2/arg3>" , '<' , '>', '/'};
	assert(test_flag.name() == "test" &&"Assert fail in Flag class constructor");

	test_flag.rconstruct("reconstruct_test<arg1'/arg2'/arg3'>");
	assert(test_flag.name() == "reconstruct_test" &&"Assert fail in Flag class rconstruct function");

	bool check = test_flag.inspect(predicate);
	assert(check &&"Assert fail in Flag inspect function");

	//std::cout<<std::boolalpha<<yt::isFlag("t<arg1 arg2>" , '<' , '>')<<std::endl;
	
}

void UT_Command()
{
	
	auto numPredicate = [](const std::string& str ) -> bool
	{
		return std::all_of(std::begin(str) , std::end(str) , isdigit);
	};

	auto alphaPredicate = [](const std::string& str ) -> bool
	{
		return std::all_of(std::begin(str) , std::end(str) , isalpha);
	};

	yt::Command com{"prog command1 arg1 arg2 arg3 flag1<arg1/arg2> flag2<1/2/3/>" , '<' , '>' , '/'};
	
	std::cout<<com.m_flagv[1][2]<<std::endl;;
	assert(com.argCount() == 3 && "func Flag::argCount()");
	

	assert(com.fArgCount() == 5 && "func Flag::fargCount()");
	
	assert(com.fArgCount("flag1") == 2 && "func Flag::fargCount(const std::string&)");
	assert(com.fArgCount("flag2") == 3 && "func Flag::fargCount(const std::string&)");

	assert(com.fCount() == 2 && "func Flag::fCount()");

	assert(com.inspect(numPredicate) == false && "assert fail : in FLag::inspect()");
	assert(com.inspectAll(numPredicate) == false && "assert fail : in FLag::inspectAll()");
	assert(com.inspectF(numPredicate) == false && "assert fail : in FLag::inspectF()");
	assert(com.inspectF("flag1" , numPredicate) == false && "assert fail : in FLag::inspectF(name , predicate)");
	assert(com.inspectF("flag2" , alphaPredicate) == false && "assert fail : in FLag::inspectF(name , predicate)");
	

}



