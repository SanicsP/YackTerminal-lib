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
	// constructor copy & operators
	{
		yt::Field field1{"g++ arg1 main.cpp -o main.exe"};
		yt::Field field2{"g++ arg2 main.cpp -I yt/include -L yt/lib -lyt-Arg.a"};
		yt::Field with_cpy_constructor{field1};
		assert(with_cpy_constructor.name() == "arg1" && "Field::Field(const Field& other)");
		with_cpy_constructor = field2;
		assert(with_cpy_constructor.name() == "arg2" && "Field::Field(const Field& other)");

	}


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

	std::vector<std::string> split_flag{
		"flag[arg1" , "arg2" , "arg3]"
	};
	std::vector<std::string>::const_iterator it = std::cbegin(split_flag);
	std::pair<std::string , std::vector<std::string>::const_iterator> flag = yt::repastFlag(split_flag , it, '[' , ']' , ' ');
	
	assert(flag.first != "" && "assert fail ! ");

	split_flag = {
		"flag[arg1" , "arg3]"
	};
	 it = std::cbegin(split_flag);
	flag = yt::repastFlag(split_flag , it, '[' , ']' , ' ');
	assert(flag.first != "" && "assert fail ! ");

	split_flag = {
		"flag[arg1]" , "arg3]"
	};

	 it = std::cbegin(split_flag);
	
	flag = yt::repastFlag(split_flag , it, '[' , ']' , ' ');
	
	
	

	
}

void UT_Command()
{
	//constructors 
	{
		yt::Command com1{"g++ compile main.cpp -o<main.exe a>" , '<' , '>' , ' '};
		yt::Command com2{"g++ linker main.o lib.o utils.o -n<app.exe a>" , '<' , '>' , ' '};
		yt::Command with_cpy_crst{com1};


		assert(with_cpy_crst.name() == "compile" && "Command::Command(Const Command& other)");
		assert(with_cpy_crst.hasFlag("-o") == true && "Command::Command(Const Command& other)");

		with_cpy_crst = com2; 
		assert(with_cpy_crst.name() == "linker" && "Command::operator=(Const Command& other)");
		assert(with_cpy_crst.hasFlag("-n") == true && "Command::operator=(Const Command& other)");

		std::cout<<"ok"<<std::endl;
	}

	auto print_argv = [](const std::vector<std::string>& argv) -> void {
		std::cout<<"\\* ArgVPrint\n-----------------------------------\n";
		for(auto str : argv )
			std::cout<<str<<'\n';
		std::cout<<"-----------------------------------*\\ \n";
		
	};
	yt::Command test_com{"gcc compile main.cpp -o<yoyo> source.cpp " , '<' , '>' , ' '};
	
	print_argv(test_com.m_com_argv);


	auto numPredicate = [](const std::string& str ) -> bool
	{
		return std::all_of(std::begin(str) , std::end(str) , isdigit);
	};

	auto alphaPredicate = [](const std::string& str ) -> bool
	{
		return std::all_of(std::begin(str) , std::end(str) , isalpha);
	};

	yt::Command com{"prog command1 arg1 arg2 arg3 flag1<arg1 arg2> flag2<1 2 3>" , '<' , '>' , ' '};
	
	print_argv(com.m_com_argv);

	std::cout<<com.m_flagv[1].m_argv.size()<<std::endl;
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



